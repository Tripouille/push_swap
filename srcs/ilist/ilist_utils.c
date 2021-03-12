#include "ilist.h"

t_ilist_element	*create_ilist_element(int i, t_ilist_element *prev,
									t_ilist_element *next)
{
	t_ilist_element	*new_ilist_element;

	new_ilist_element = malloc(sizeof(*new_ilist_element));
	if (new_ilist_element == NULL)
		return (NULL);
	new_ilist_element->i = i;
	new_ilist_element->prev = prev;
	new_ilist_element->next = next;
	return (new_ilist_element);
}

t_ilist_element	*ilist_inject(t_ilist *ilist, int i)
{
	t_ilist_element	*new_ilist_element;

	new_ilist_element = create_ilist_element(i, ilist->tail, ilist->head);
	if (new_ilist_element == NULL)
	{
		ilist_destroy(ilist);
		return (NULL);
	}
	if (ilist->head == NULL)
	{
		ilist->head = new_ilist_element;
		ilist->tail = new_ilist_element;
	}
	ilist->tail->next = new_ilist_element;
	ilist->head->prev = new_ilist_element;
	ilist->size += 1;
	return (new_ilist_element);
}

void	ilist_destroy(t_ilist *ilist)
{
	t_ilist_element	*element;
	t_ilist_element	*element_next;

	element = ilist->head;
	while (element != ilist->tail)
	{
		element_next = element->next;
		free(element);
		element = element_next;
	}
	free(ilist->tail);
	ilist->head = NULL;
	ilist->tail = NULL;
}

void	ilist_show(t_ilist const *ilist, char sep)
{
	t_ilist_element	*element;

	if (ilist->head == NULL)
	{
		printf("\n");
		return ;
	}
	element = ilist->head;
	while (element != ilist->tail)
	{
		printf("%i%c", element->i, sep);
		element = element->next;
	}
	if (element != NULL)
		printf("%i\n", element->i);
}
