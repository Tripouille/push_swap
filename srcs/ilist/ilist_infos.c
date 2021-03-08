#include "ilist.h"

bool					ilist_is_sort(t_ilist *ilist, bool descending)
{
	t_ilist_element *element;

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

bool					ilist_is_globally_sort(t_ilist *ilist, t_ilist_element *smallest)
{
	t_ilist_element *element;

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

bool					ilist_contain(t_ilist *ilist, int needle)
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

size_t					ilist_size(t_ilist *ilist)
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

bool					ilist_is_empty(t_ilist *ilist)
{
	return (ilist->head == NULL);
}

void					ilist_show(t_ilist ilist, bool reverse)
{
	t_ilist_element *element;
	if (ilist.head == NULL)
	{
		dprintf(2, "\n");
		return ;
	}
	else if (reverse)
	{
		element = ilist.tail;
		while (element != ilist.head)
		{
			dprintf(2, "%i ", element->i);
			element = element->prev;
		}
	}
	else
	{
		element = ilist.head;
		while (element != ilist.tail)
		{
			dprintf(2, "%i ", element->i);
			element = element->next;
		}
	}
	dprintf(2, "%i\n", element->i);
}
