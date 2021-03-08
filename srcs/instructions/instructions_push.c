#include "instructions.h"

void	instructions_push_a(t_stacks *stacks)
{
	if (ilist_is_empty(&stacks->b))
		return ;
	ilist_unshift(&stacks->a, ilist_shift(&stacks->b));
}

void	instructions_push_b(t_stacks *stacks)
{
	if (ilist_is_empty(&stacks->a))
		return ;
	ilist_unshift(&stacks->b, ilist_shift(&stacks->a));
}
