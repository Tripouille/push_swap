#include "slist.h"

void	slist_initialize(t_slist *slist)
{
	slist->head = NULL;
	slist->tail = NULL;
}

t_slist_element	*slist_push(t_slist *slist, char const *s)
{
	t_slist_element	*injected_element;

	injected_element = slist_inject(slist, s);
	if (injected_element == NULL)
		return (NULL);
	slist->tail = injected_element;
	return (injected_element);
}

void	slist_pop(t_slist *slist)
{
	t_slist_element	*element_to_destroy;

	element_to_destroy = slist->tail;
	if (slist->head == slist->tail)
	{
		slist->head = NULL;
		slist->tail = NULL;
	}
	else
	{
		slist->tail->prev->next = slist->tail->next;
		slist->tail->next->prev = slist->tail->prev;
		slist->tail = slist->tail->prev;
	}
	free(element_to_destroy);
}

t_slist_element	*slist_unshift(t_slist *slist, char const *s)
{
	t_slist_element	*injected_element;

	injected_element = slist_inject(slist, s);
	if (injected_element == NULL)
		return (NULL);
	slist->head = injected_element;
	return (injected_element);
}

void	slist_shift(t_slist *slist)
{
	t_slist_element	*element_to_destroy;

	element_to_destroy = slist->head;
	if (slist->head == slist->tail)
	{
		slist->head = NULL;
		slist->tail = NULL;
	}
	else
	{
		slist->head->next->prev = slist->head->prev;
		slist->head->prev->next = slist->head->next;
		slist->head = slist->head->next;
	}
	free(element_to_destroy);
}
