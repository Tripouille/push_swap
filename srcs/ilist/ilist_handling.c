#include "ilist.h"

void ilist_swap(t_ilist *ilist)
{
	t_ilist_element *old_first_element;

	if (ilist->head == ilist->tail)
		return ;
	old_first_element = ilist->head;
	ilist->head = old_first_element->next;
	old_first_element->prev->next = old_first_element->next;
	old_first_element->next->prev = old_first_element->prev;
	old_first_element->next = ilist->head->next;
	old_first_element->prev = ilist->head;
	ilist->head->next->prev = old_first_element;
	ilist->head->next = old_first_element;
	if (ilist->head == ilist->tail)
		ilist->tail = old_first_element;
}

void ilist_rotate(t_ilist *ilist)
{
	if (ilist->head == ilist->tail)
		return ;
	ilist->head = ilist->head->next;
	ilist->tail = ilist->tail->next;
}

void ilist_reverse_rotate(t_ilist *ilist)
{
	if (ilist->head == ilist->tail)
		return ;
	ilist->head = ilist->head->prev;
	ilist->tail = ilist->tail->prev;
}
