#include "slist.h"

size_t					slist_size(t_slist *slist)
{
	t_slist_element	*element;
	size_t			size;

	element = slist->head;
	size = 0;
	while (element != slist->tail)
	{
		element = element->next;
		size += 1;
	}
	if (slist->tail != NULL)
		size += 1;
	return (size);
}

void					slist_show(t_slist slist, bool reverse)
{
	t_slist_element *element;
	if (slist.head == NULL)
		return ;
	else if (reverse)
	{
		element = slist.tail;
		while (element != slist.head)
		{
			printf("%s ", element->s);
			element = element->prev;
		}
	}
	else
	{
		element = slist.head;
		while (element != slist.tail)
		{
			printf("%s ", element->s);
			element = element->next;
		}
	}
	printf("%s\n", element->s);
}
