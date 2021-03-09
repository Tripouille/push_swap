#include "stacks.h"

void	stacks_init(t_stacks *stacks)
{
	ilist_initialize(&stacks->a);
	ilist_initialize(&stacks->b);
}

t_stacks	*stacks_destroy(t_stacks *stacks)
{
	ilist_destroy(&stacks->a);
	ilist_destroy(&stacks->b);
	return (stacks);
}

t_stacks	stacks_clone(t_stacks const *src)
{
	t_stacks			clone;
	t_ilist_element		*element;

	stacks_init(&clone);
	element = src->a.head;
	while (element != src->a.tail)
	{
		if (ilist_push(&clone.a, element->i) == NULL)
			return (*stacks_destroy(&clone));
		element = element->next;
	}
	if (src->a.tail != NULL && ilist_push(&clone.a, src->a.tail->i) == NULL)
		return (*stacks_destroy(&clone));
	element = src->b.head;
	while (element != src->b.tail)
	{
		if (ilist_push(&clone.b, element->i) == NULL)
			return (*stacks_destroy(&clone));
		element = element->next;
	}
	if (src->b.tail != NULL && ilist_push(&clone.b, src->b.tail->i) == NULL)
		return (*stacks_destroy(&clone));
	return (clone);
}
