#include "benchmark.h"

t_benchmark const	*get_benchmark(t_benchmark const benchmark[], char const *algo_name)
{
    int		i;

	i = -1;
	while (benchmark[++i].algo != NULL)
        if (!ft_strcmp(benchmark[i].name, algo_name))
            return (benchmark + i);
    return (NULL);
}

t_benchmark const	*get_best_benchmark(t_benchmark const benchmark[])
{
	int					i;
	t_benchmark const	*best_benchmark;
	size_t				lowest_size;
	size_t				actual_size;

	i = 0;
	best_benchmark = benchmark;
	lowest_size = benchmark[0].required_instructions.size;
	while (benchmark[++i].algo != NULL)
	{
		actual_size = benchmark[i].required_instructions.size;
		if (actual_size < lowest_size)
		{
			lowest_size = actual_size;
			best_benchmark = benchmark + i;
		}
	}
	return (best_benchmark);
}

void	benchmark_show(t_benchmark const benchmark[])
{
	int		i;

	i = -1;
	while (benchmark[++i].algo != NULL)
		dprintf(2, "[%s %lu] ", benchmark[i].name,
			benchmark[i].required_instructions.size);
	dprintf(2, "\n");
}

bool    benchmark_contain(t_benchmark const benchmark[], char const *algo_name)
{
    int		i;

	if (algo_name == NULL)
		return (false);
	i = -1;
	while (benchmark[++i].algo != NULL)
        if (!ft_strcmp(benchmark[i].name, algo_name))
            return (true);
    return (false);
}