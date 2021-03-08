#include "instructions.h"

void	instructions_rotate_a(t_stacks *stacks)
{
	ilist_rotate(&stacks->a);
}

void	instructions_rotate_b(t_stacks *stacks)
{
	ilist_rotate(&stacks->b);
}

void	instructions_rotate_ab(t_stacks *stacks)
{
	ilist_rotate(&stacks->a);
	ilist_rotate(&stacks->b);
}
