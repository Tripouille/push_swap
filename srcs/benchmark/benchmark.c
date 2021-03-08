#include "benchmark.h"

static void	benchmark_set(t_benchmark benchmark[], size_t pos,
							char const *name, t_algorithm algo)
{
	benchmark[pos].name = name;
	benchmark[pos].algo = algo;
}

static void	benchmark_init(t_benchmark benchmark[])
{
	benchmark_set(benchmark, 0, "selection_sort", &selection_sort);
	benchmark_set(benchmark, 1, "quick_sort", &quick_sort);
	benchmark_set(benchmark, 2, "", NULL);
}

static void	benchmark_launch(t_instruction_infos const instructions[],
								t_stacks const *stacks, t_benchmark benchmark[])
{
	int						i;
	t_stacks				stacks_copy;

	i = -1;
	while (benchmark[++i].algo != NULL)
	{
		stacks_copy = stacks_clone(stacks);
		benchmark[i].required_instructions
			= benchmark[i].algo(instructions, &stacks_copy);
		stacks_destroy(&stacks_copy);
	}
}

static void	benchmark_destroy(t_benchmark benchmark[])
{
	int						i;

	i = -1;
	while (benchmark[++i].algo != NULL)
		slist_destroy(&benchmark[i].required_instructions);
}

void	print_best_algo(t_instruction_infos const instructions[],
						t_stacks const *stacks)
{
	t_benchmark			benchmark[10];
	t_benchmark const	*best_benchmark;
	t_slist_element		*instruction;

	if (ilist_is_sort(&stacks->a, false))
		return ;
	benchmark_init(benchmark);
	benchmark_launch(instructions, stacks, benchmark);
	best_benchmark = get_best_benchmark(benchmark);
	instruction = best_benchmark->required_instructions.head;
	while (instruction != best_benchmark->required_instructions.tail)
	{
		printf("%s\n", instruction->s);
		instruction = instruction->next;
	}
	printf("%s\n", instruction->s);
	benchmark_show(benchmark);
	benchmark_destroy(benchmark);
}
