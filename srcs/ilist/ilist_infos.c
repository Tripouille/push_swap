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
            if (element->next->value > element->value)
                return (false);
            element = element->next;
        }
    }
    else
    {
        while (element != ilist->tail)
        {
            if (element->next->value < element->value)
                return (false);
            element = element->next;
        }   
    }
    return (true);
}

bool					ilist_contain(t_ilist *ilist, int needle)
{
    t_ilist_element	*element;

    if (ilist->head == NULL)
        return (false);
    element = ilist->head;
    while (element != ilist->tail)
    {
        if (element->value == needle)
            return (true);
        element = element->next;
    }
    return (ilist->tail->value == needle);
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

void					ilist_show(t_ilist ilist, bool reverse)
{
    t_ilist_element *element;
	if (ilist.head == NULL)
		return ;
	else if (reverse)
	{
		element = ilist.tail;
		while (element != ilist.head)
		{
			printf("%i ", element->value);
			element = element->prev;
		}
	}
	else
	{
		element = ilist.head;
		while (element != ilist.tail)
		{
			printf("%i ", element->value);
			element = element->next;
		}
	}
    printf("%i\n", element->value);
}
