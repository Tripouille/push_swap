#include "instructions.h"

void	instructions_reverse_rotate_a(t_ilist *a, t_ilist *b)
{
    ilist_reverse_rotate(a);
    (void)b;
}

void	instructions_reverse_rotate_b(t_ilist *a, t_ilist *b)
{
    (void)a;
    ilist_reverse_rotate(b);
}

void	instructions_reverse_rotate_ab(t_ilist *a, t_ilist *b)
{
    ilist_reverse_rotate(a);
    ilist_reverse_rotate(b);
}
