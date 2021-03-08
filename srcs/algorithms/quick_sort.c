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
		pivot = get_pivot(&stacks->a);
		if (pivot == NULL)
		{
			if (!ilist_is_empty(&stacks->b))
			{
				stock_and_call(instructions, &requiredInstructions, "pa", stacks);
				continue ;
			}
			else
				break ;
		}
		while (pivot != stacks->a.head)
		{
			if (stacks->a.head->i < pivot->i)
				stock_and_call(instructions, &requiredInstructions, "pb", stacks);
			else if (ilist_is_globally_sort(&stacks->a, ilist_get_smallest(&stacks->a))
			&& ft_strcmp(get_best_rotate_dir(stacks, pivot), "rra") == 0)
				while (pivot != stacks->a.head)
					stock_and_call(instructions, &requiredInstructions, "rra", stacks);
			else
				stock_and_call(instructions, &requiredInstructions, "ra", stacks);
		}
	}
	return (requiredInstructions);
}