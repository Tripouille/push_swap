#include "list.h"

t_list_element	*create_list_element(void *data, t_list_element *prev,
									t_list_element *next)
{
	t_list_element	*new_list_element;

	new_list_element = malloc(sizeof(*new_list_element));
	if (new_list_element == NULL)
		return (NULL);
	new_list_element->data = data;
	new_list_element->prev = prev;
	new_list_element->next = next;
	return (new_list_element);
}

t_list_element	*list_push(t_list *list, void *data)
{
	t_list_element	*new_list_element;

	new_list_element = create_list_element(data, NULL, NULL);
	if (new_list_element == NULL)
		return (NULL);
	if (list->head == NULL)
	{
		list->head = new_list_element;
		list->tail = new_list_element;
	}
	else
	{
		new_list_element->prev = list->tail;
		list->tail->next = new_list_element;
		new_list_element->next = list->head;
		list->head->prev = new_list_element;
	}
	return (new_list_element);
}
