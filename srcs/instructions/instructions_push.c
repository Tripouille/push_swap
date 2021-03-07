#include "instructions.h"

void	instructions_push_a(t_ilist *a, t_ilist *b)
{
	if (ilist_size(b) == 0)
		return ;
	ilist_unshift(a, ilist_shift(b));
}

void	instructions_push_b(t_ilist *a, t_ilist *b)
{
	if (ilist_size(a) == 0)
		return ;
	ilist_unshift(b, ilist_shift(a));
}
