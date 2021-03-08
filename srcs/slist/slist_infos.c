#include "slist.h"

size_t	slist_size(t_slist const *slist)
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

void	slist_show(t_slist const slist)
{
	t_slist_element	*element;

	element = slist.head;
	while (element != slist.tail)
	{
		printf("%s ", element->s);
		element = element->next;
	}
	printf("%s\n", element->s);
}
