#include "instructions.h"

void	instructions_swap_a(t_ilist *a, t_ilist *b)
{
	ilist_swap(a);
	(void)b;
}

void	instructions_swap_b(t_ilist *a, t_ilist *b)
{
	(void)a;
	ilist_swap(b);
}

void	instructions_swap_ab(t_ilist *a, t_ilist *b)
{
	ilist_swap(a);
	ilist_swap(b);
}
