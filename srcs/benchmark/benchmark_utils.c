#include "benchmark.h"

t_benchmark const	*get_best_benchmark(t_benchmark const benchmark[])
{
	int					i;
	t_benchmark const	*best_benchmark;
	size_t				lowest_size;
	size_t				actual_size;

	i = 0;
	best_benchmark = benchmark;
	lowest_size = slist_size(&benchmark[0].required_instructions);
	while (benchmark[++i].algo != NULL)
	{
		actual_size = slist_size(&benchmark[i].required_instructions);
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
			slist_size(&benchmark[i].required_instructions));
	dprintf(2, "\n");
}
