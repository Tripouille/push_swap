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

bool	ilist_is_empty(t_ilist *ilist)
{
	return (ilist->head == NULL);
}
