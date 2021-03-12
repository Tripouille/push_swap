#include "slist.h"

void	slist_show(t_slist const *slist, char sep)
{
	t_slist_element	*element;

	element = slist->head;
	while (element != slist->tail)
	{
		printf("%s%c", element->s, sep);
		element = element->next;
	}
	printf("%s\n", element->s);
}

void	slist_show_color(t_slist const *slist, char sep)
{
	t_slist_element	*element;

	element = slist->head;
	while (element != slist->tail)
	{
		printf("%s%c", element->s, sep);
		element = element->next;
	}
	printf("\033[32m%s\033[0m\n", element->s);
}
