#include "ilist.h"

void	ilist_initialize(t_ilist *ilist)
{
	ilist->head = NULL;
	ilist->tail = NULL;
	ilist->size = 0;
}

t_ilist_element	*ilist_push(t_ilist *ilist, int i)
{
	t_ilist_element	*injected_element;

	injected_element = ilist_inject(ilist, i);
	if (injected_element == NULL)
		return (NULL);
	ilist->tail = injected_element;
	return (injected_element);
}

int	ilist_pop(t_ilist *ilist)
{
	t_ilist_element	*element_to_destroy;
	int				return_i;

	element_to_destroy = ilist->tail;
	if (ilist->tail != NULL)
		ilist->size -= 1;
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
	return_i = element_to_destroy->i;
	free(element_to_destroy);
	return (return_i);
}

t_ilist_element	*ilist_unshift(t_ilist *ilist, int i)
{
	t_ilist_element	*injected_element;

	injected_element = ilist_inject(ilist, i);
	if (injected_element == NULL)
		return (NULL);
	ilist->head = injected_element;
	return (injected_element);
}

int	ilist_shift(t_ilist *ilist)
{
	t_ilist_element	*element_to_destroy;
	int				return_i;

	element_to_destroy = ilist->head;
	if (ilist->head != NULL)
		ilist->size -= 1;
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
	return_i = element_to_destroy->i;
	free(element_to_destroy);
	return (return_i);
}
