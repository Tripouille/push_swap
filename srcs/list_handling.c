#include "list.h"

void list_swap(t_list *list)
{
    t_list_element *old_first_element;

    if (list->head == list->tail)
        return ;
    old_first_element = list->head;
    list->head = old_first_element->next;
    old_first_element->prev->next = old_first_element->next;
    old_first_element->next->prev = old_first_element->prev;
    old_first_element->next = list->head->next;
    old_first_element->prev = list->head;
    list->head->next->prev = old_first_element;
    list->head->next = old_first_element;
    if (list->head == list->tail)
        list->tail = old_first_element;
}

void list_rotate(t_list *list)
{
    if (list->head == list->tail)
        return ;
    list->head = list->head->next;
    list->tail = list->tail->next;
}

void list_reverse_rotate(t_list *list)
{
    if (list->head == list->tail)
        return ;
    list->head = list->head->prev;
    list->tail = list->tail->prev;
}
