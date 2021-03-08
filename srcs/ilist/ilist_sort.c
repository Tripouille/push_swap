#include "ilist.h"

bool	ilist_is_sort(t_ilist const *ilist, bool descending)
{
	t_ilist_element	*element;

	if (ilist->head == ilist->tail)
		return (true);
	element = ilist->head;
	if (descending)
	{
		while (element != ilist->tail)
		{
			if (element->next->i > element->i)
				return (false);
			element = element->next;
		}
	}
	else
	{
		while (element != ilist->tail)
		{
			if (element->next->i < element->i)
				return (false);
			element = element->next;
		}
	}
	return (true);
}

bool	ilist_is_globally_sort(t_ilist *ilist, t_ilist_element *smallest)
{
	t_ilist_element	*element;

	if (ilist->head == ilist->tail)
		return (true);
	element = smallest;
	while (element != smallest->prev)
	{
		if (element->i > element->next->i)
			return (false);
		element = element->next;
	}
	return (smallest->prev->i < smallest->i);
}

bool	ilist_is_globally_sort2(t_ilist *ilist, bool reverse)
{
	t_ilist_element *element;
	bool			metEnd;

	metEnd = false;
	element = ilist->head;
	while (element != ilist->tail)
	{
		if ((!reverse && element->i > element->next->i)
		|| (reverse && element->i < element->next->i))
		{
			if (metEnd)
				return (false);
			metEnd = true;
		}
		element = element->next;
	}
	return (!metEnd
	|| (!reverse && ilist->tail->i < ilist->head->i)
	|| (reverse && ilist->tail->i > ilist->head->i));
}

