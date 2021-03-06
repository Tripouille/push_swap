#include "ilist.h"

void					ilist_initialize(t_ilist *ilist)
{
	ilist->head = NULL;
	ilist->tail = NULL;
}

t_ilist_element			*ilist_push(t_ilist *ilist, int value)
{
	t_ilist_element	*injected_element;

	injected_element = ilist_inject(ilist, value);
	if (injected_element == NULL)
		return (NULL);
	ilist->tail = injected_element;
	return (injected_element);
}

int						ilist_pop(t_ilist *ilist)
{
	t_ilist_element	*element_to_destroy;
	int				return_value;

	element_to_destroy = ilist->tail;
	if (ilist->head == ilist->tail)
	{
		ilist->head = NULL;
		ilist->tail = NULL;
	}
	else
	{
		ilist->tail->prev->next = ilist->tail->next;
		ilist->tail->next->prev = ilist->tail->prev;
		ilist->tail = ilist->tail->prev;
	}
	return_value = element_to_destroy->value;
	free(element_to_destroy);
	return (return_value);
}

t_ilist_element			*ilist_unshift(t_ilist *ilist, int value)
{
	t_ilist_element	*injected_element;

	injected_element = ilist_inject(ilist, value);
	if (injected_element == NULL)
		return (NULL);
	ilist->head = injected_element;
	return (injected_element);
}

int						ilist_shift(t_ilist *ilist)
{
	t_ilist_element	*element_to_destroy;
	int				return_value;

	element_to_destroy = ilist->head;
	if (ilist->head == ilist->tail)
	{
		ilist->head = NULL;
		ilist->tail = NULL;
	}
	else
	{
		ilist->head->next->prev = ilist->head->prev;
		ilist->head->prev->next = ilist->head->next;
		ilist->head = ilist->head->next;
	}
	return_value = element_to_destroy->value;
	free(element_to_destroy);
	return (return_value);
}
