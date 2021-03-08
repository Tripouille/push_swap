#include "instructions.h"

void	instructions_swap_a(t_stacks *stacks)
{
	ilist_swap(&stacks->a);
}

void	instructions_swap_b(t_stacks *stacks)
{
	ilist_swap(&stacks->b);
}

void	instructions_swap_ab(t_stacks *stacks)
{
	ilist_swap(&stacks->a);
	ilist_swap(&stacks->b);
}
