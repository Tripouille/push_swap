#include "instructions.h"

void	instructions_reverse_rotate_a(t_stacks *stacks)
{
	ilist_reverse_rotate(&stacks->a);
}

void	instructions_reverse_rotate_b(t_stacks *stacks)
{
	ilist_reverse_rotate(&stacks->b);
}

void	instructions_reverse_rotate_ab(t_stacks *stacks)
{
	ilist_reverse_rotate(&stacks->a);
	ilist_reverse_rotate(&stacks->b);
}
