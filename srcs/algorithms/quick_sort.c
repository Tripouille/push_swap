#include "algorithms.h"

static bool	is_greater_than_above(t_ilist_element *base_element, t_ilist *a)
{
	t_ilist_element *element;

	element = base_element->prev;
	while (element != a->head)
	{
		if (element->i > base_element->i)
			return (false);
		element = element->prev;
	}
	return (base_element->i > a->head->i);
}

static t_ilist_element*	get_pivot(t_ilist *a)
{
	t_ilist_element	*element;

	element = a->tail;
	while (element != a->head)
	{
		if (!is_greater_than_above(element, a))
			return (element);
		element = element->prev;
	}
	return (NULL);
}

t_slist	quick_sort(t_instruction_infos instructions[], t_stacks *stacks)
{
	t_slist			requiredInstructions;
	t_ilist_element	*pivot;

	slist_initialize(&requiredInstructions);
	while (true)
	{
		dprintf(2, "a : "); ilist_show(stacks->a, false);
		dprintf(2, "b : "); ilist_show(stacks->b, false);
		pivot = get_pivot(&stacks->a);
		if (pivot == NULL)
		{
			dprintf(2, "pivot is NULL\n\n");
			if (!ilist_is_empty(&stacks->b))
			{
				stock_and_call(instructions, &requiredInstructions, "pa", stacks);
				continue ;
			}
			else
				break ;
		}
		dprintf(2, "pivot = %i\n\n", pivot->i);
		while (pivot->prev != stacks->a.tail)
		{
			if (stacks->a.head->i < pivot->i)
				stock_and_call(instructions, &requiredInstructions, "pb", stacks);
			//else if (ilist_is_globally_sort(&stacks->a, ilist_get_smallest(&stacks->a))
			//&& ilist_)
			//	stock_and_call(instructions, &requiredInstructions, "rra", stacks);
			else
				stock_and_call(instructions, &requiredInstructions, "ra", stacks);
		}
	}
	return (requiredInstructions);
}