#ifndef STACKS_H
# define STACKS_H
# include "ilist.h"
typedef struct s_stacks
{
	t_ilist		a;
	t_ilist		b;
}				t_stacks;

void		stacks_init(t_stacks *stacks);
void		stacks_destroy(t_stacks *stacks);
t_stacks	stacks_clone(t_stacks *src);

#endif