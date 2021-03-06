#include "instructions.h"

void	instructions_rotate_a(t_ilist *a, t_ilist *b)
{
    ilist_rotate(a);
    (void)b;
}

void	instructions_rotate_b(t_ilist *a, t_ilist *b)
{
    (void)a;
    ilist_rotate(b);
}

void	instructions_rotate_ab(t_ilist *a, t_ilist *b)
{
    ilist_rotate(a);
    ilist_rotate(b);
}
