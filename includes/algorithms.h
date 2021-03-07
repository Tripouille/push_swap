#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "ilist.h"
# include "slist.h"
# include "instructions.h"

typedef struct s_stacks
{
	t_ilist		a;
	t_ilist		b;
}				t_stacks;

void		stock_and_call(t_slist *instructionNames, t_instruction_infos const instructions[],
							char const *name, t_stacks *stacks);

t_slist		franky_sort(t_instruction_infos instructions[], t_stacks *stacks);

#endif