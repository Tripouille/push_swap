#ifndef BENCHMARK_H
# define BENCHMARK_H
# include "slist.h"
# include "instructions.h"
# include "stacks.h"
# include "algorithms.h"
# include "options.h"

typedef t_slist	(*t_algorithm)(t_instruction_infos const instructions[],
	t_stacks *stacks);

typedef struct s_benchmark
{
	char const		*name;
	t_algorithm		algo;
	t_slist			required_instructions;
}				t_benchmark;

void				print_best_algo(t_instruction_infos const instructions[],
						t_stacks const *stacks, t_option options[]);


t_benchmark const	*get_benchmark(t_benchmark const benchmark[], char const *algo_name);
t_benchmark const	*get_best_benchmark(t_benchmark const benchmark[]);
void				benchmark_show(t_benchmark const benchmark[]);
bool                benchmark_contain(t_benchmark const benchmark[], char const *algo_name);


#endif