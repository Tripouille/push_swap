#include "benchmark.h"

static void	benchmark_destroy(t_benchmark benchmark[])
{
	int						i;

	i = -1;
	while (benchmark[++i].algo != NULL)
		slist_destroy(&benchmark[i].required_instructions);
}

static void	benchmark_set(t_benchmark benchmark[], size_t pos,
							char const *name, t_algorithm algo)
{
	benchmark[pos].name = name;
	benchmark[pos].algo = algo;
	slist_initialize(&benchmark[pos].required_instructions);
}

static void	benchmark_init(t_benchmark benchmark[])
{
	benchmark_set(benchmark, 0, "selection_sort", &selection_sort);
	benchmark_set(benchmark, 1, "quick_sort", &quick_sort);
	benchmark_set(benchmark, 2, "jm_sort", &jm_sort);
	benchmark_set(benchmark, 3, "", NULL);
}

static bool	benchmark_launch(t_instruction_infos const instructions[],
								t_stacks const *stacks, t_benchmark benchmark[])
{
	int						i;
	t_stacks				stacks_copy;

	i = -1;
	while (benchmark[++i].algo != NULL)
	{
		stacks_copy = stacks_clone(stacks);
		if (stacks_copy.a.head == NULL)
		{
			benchmark_destroy(benchmark);
			return (false);
		}
		benchmark[i].required_instructions
			= benchmark[i].algo(instructions, &stacks_copy);
		stacks_destroy(&stacks_copy);
	}
	return (true);
}

void	print_best_algo(t_instruction_infos const instructions[],
						t_stacks const *stacks)
{
	t_benchmark			benchmark[10];

	if (ilist_is_sort(&stacks->a, false))
		return ;
	benchmark_init(benchmark);
	if (!benchmark_launch(instructions, stacks, benchmark))
		return ;
	slist_show(&get_best_benchmark(benchmark)->required_instructions, '\n');
	//benchmark_show(benchmark);
	benchmark_destroy(benchmark);
}
