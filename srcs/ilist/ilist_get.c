#include "ilist.h"

t_ilist_element	*ilist_get_smallest(t_ilist const *ilist)
{
	t_ilist_element	*smallest;
	t_ilist_element	*element;

	smallest = ilist->head;
	element = ilist->head;
	while (element != ilist->tail)
	{
		if (element->i < smallest->i)
			smallest = element;
		element = element->next;
	}
	if (smallest->i < ilist->tail->i)
		return (smallest);
	return (ilist->tail);
}

t_ilist_element	*ilist_get_biggest(t_ilist const *ilist)
{
	t_ilist_element	*biggest;
	t_ilist_element	*element;

	biggest = ilist->head;
	element = ilist->head;
	while (element != ilist->tail)
	{
		if (element->i > biggest->i)
			biggest = element;
		element = element->next;
	}
	if (biggest->i > ilist->tail->i)
		return (biggest);
	return (ilist->tail);
}
