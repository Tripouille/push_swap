#include "stacks.h"

void		stacks_init(t_stacks *stacks)
{
		ilist_initialize(&stacks->a);
		ilist_initialize(&stacks->b);
}

void		stacks_destroy(t_stacks *stacks)
{
		ilist_destroy(&stacks->a);
		ilist_destroy(&stacks->b);
}

t_stacks	stacks_clone(t_stacks *src)
{
	t_stacks		clone;
	t_ilist_element	*element;

	stacks_init(&clone);
	element = src->a.head;
	while (element != src->a.tail)
	{
		ilist_push(&clone.a, element->i);
		element = element->next;
	}
	if (src->a.tail != NULL)
		ilist_push(&clone.a, src->a.tail->i);
	element = src->b.head;
	while (element != src->b.tail)
	{
		ilist_push(&clone.b, element->i);
		element = element->next;
	}
	if (src->b.tail != NULL)
		ilist_push(&clone.b, src->b.tail->i);
	return (clone);
}
