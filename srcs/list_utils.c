#include "list.h"

t_list_element	*create_list_element(int value, t_list_element *prev,
									t_list_element *next)
{
	t_list_element	*new_list_element;

	new_list_element = malloc(sizeof(*new_list_element));
	if (new_list_element == NULL)
		return (NULL);
	new_list_element->value = value;
	new_list_element->prev = prev;
	new_list_element->next = next;
	return (new_list_element);
}

t_list_element			*list_inject(t_list *list, int value)
{
	t_list_element	*new_list_element;

	new_list_element = create_list_element(value, list->tail, list->head);
	if (new_list_element == NULL)
	{
		list_destroy(list);
		return (NULL);
	}
	else if (list->head == NULL)
	{
		list->head = new_list_element;
		list->tail = new_list_element;
	}
	else
	{
		list->tail->next = new_list_element;
		list->head->prev = new_list_element;
	}
	return (new_list_element);
}

size_t					list_size(t_list *list)
{
    t_list_element	*element;
	size_t			size;

	element = list->head;
	size = 0;
	while (element != list->tail)
	{
		element = element->next;
		size += 1;
	}
	if (list->tail != NULL)
		size += 1;
	return (size);
}

void					list_destroy(t_list *list)
{
    t_list_element *element;
    t_list_element *element_next;

	element = list->head;
	while (element != list->tail)
	{
		element_next = element->next;
		free(element);
		element = element_next;
	}
	free(list->tail);
	list->head = NULL;
	list->tail = NULL;
}

void					list_show(t_list list, bool reverse)
{
    t_list_element *element;
	if (list.head == NULL)
		return ;
	else if (reverse)
	{
		element = list.tail;
		while (element != list.head)
		{
			printf("%i ", element->value);
			element = element->prev;
		}
	}
	else
	{
		element = list.head;
		while (element != list.tail)
		{
			printf("%i ", element->value);
			element = element->next;
		}
	}
    printf("%i\n", element->value);
}
