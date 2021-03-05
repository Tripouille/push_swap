#include "list.h"

bool					list_contain(t_list *list, int needle)
{
    t_list_element	*element;

    if (list->head == NULL)
        return (false);
    element = list->head;
    while (element != list->tail)
    {
        if (element->value == needle)
            return (true);
        element = element->next;
    }
    return (list->tail->value == needle);
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
