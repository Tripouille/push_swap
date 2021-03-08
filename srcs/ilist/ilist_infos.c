#include "ilist.h"

bool	ilist_contain(t_ilist *ilist, int needle)
{
	t_ilist_element	*element;

	if (ilist->head == NULL)
		return (false);
	element = ilist->head;
	while (element != ilist->tail)
	{
		if (element->i == needle)
			return (true);
		element = element->next;
	}
	return (ilist->tail->i == needle);
}

size_t	ilist_size(t_ilist *ilist)
{
	t_ilist_element	*element;
	size_t			size;

	element = ilist->head;
	size = 0;
	while (element != ilist->tail)
	{
		element = element->next;
		size += 1;
	}
	if (ilist->tail != NULL)
		size += 1;
	return (size);
}

bool	ilist_is_empty(t_ilist *ilist)
{
	return (ilist->head == NULL);
}
