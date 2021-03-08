#ifndef BENCHMARK_H
# define BENCHMARK_H
# include "slist.h"
# include "instructions.h"
# include "stacks.h"
# include "algorithms.h"


typedef t_slist (*algorithm)(t_instruction_infos instructions[], t_stacks *stacks);

typedef struct	s_benchmark
{
	algorithm		algo;
	t_slist			required_instructions;
}				t_benchmark;

void	print_best_algo(t_instruction_infos instructions[], t_stacks *stacks);

#endif