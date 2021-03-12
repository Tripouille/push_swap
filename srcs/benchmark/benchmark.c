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
	size_t		i;

	i = 0;
	benchmark_set(benchmark, i++, "astrid_sort", &astrid_sort);
	benchmark_set(benchmark, i++, "selection_sort", &selection_sort);
	benchmark_set(benchmark, i++, "jm_sort", &jm_sort);
	benchmark_set(benchmark, i++, "simple_swap_sort", &simple_swap_sort);
	benchmark_set(benchmark, i, "", NULL);
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
		if (benchmark[i].required_instructions.size == 0)
		{
			benchmark_destroy(benchmark);
			return (false);
		}
	}
	return (true);
}

void	print_best_algo(t_instruction_infos const instructions[],
						t_stacks const *stacks, t_option options[])
{
	t_benchmark			benchmark[10];
    t_option           *a;

	benchmark_init(benchmark);
    a = (get_option(options, 'a'));
    if (a->active && !benchmark_contain(benchmark, a->value))
		return (error());
	if (ilist_is_sort(&stacks->a, false))
		return ;
	if (!benchmark_launch(instructions, stacks, benchmark))
		return (error());
	if (a->active)
		slist_show(&get_benchmark(benchmark, a->value)->required_instructions, '\n');
	else
		slist_show(&get_best_benchmark(benchmark)->required_instructions, '\n');
    if (get_option(options, 'b')->active)
	    benchmark_show(benchmark);
	benchmark_destroy(benchmark);
}
