#include "benchmark.h"

static void	benchmark_init(t_benchmark benchmark[])
{
	benchmark[0].algo = &selection_sort;
	benchmark[1].algo = &quick_sort;
	benchmark[2].algo = NULL;
}

static void benchmark_launch(t_instruction_infos instructions[], t_stacks *stacks,
							t_benchmark benchmark[])
{
	int						i;
	t_stacks				stacks_copy;

	i = -1;
	while (benchmark[++i].algo != NULL)
	{
		stacks_copy = stacks_clone(stacks);
		benchmark[i].required_instructions = benchmark[i].algo(instructions, &stacks_copy);
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

static t_benchmark	*get_best_benchmark(t_benchmark benchmark[])
{
	int						i;
	t_benchmark				*best_benchmark;
	size_t					lowest_size;
	size_t					actual_size;

	i = 0;
	best_benchmark = benchmark;
	lowest_size = slist_size(&benchmark[0].required_instructions);
	dprintf(2, "[Algo N%i size = %lu]", 0, lowest_size);
	while (benchmark[++i].algo != NULL)
	{
		actual_size = slist_size(&benchmark[i].required_instructions);
		dprintf(2, " [Algo N%i size = %lu]", i, actual_size);
		if (actual_size < lowest_size)
		{
			lowest_size = actual_size;
			best_benchmark = benchmark + i;
		}
	}
	dprintf(2, "\n");
	return (best_benchmark);
}

void	print_best_algo(t_instruction_infos instructions[], t_stacks *stacks)
{
	t_benchmark				benchmark[10];
	t_benchmark				*best_benchmark;
	t_slist_element			*instruction;

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
	benchmark_destroy(benchmark);
}