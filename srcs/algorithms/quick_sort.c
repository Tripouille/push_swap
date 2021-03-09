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

static bool	elements_are_greater(t_ilist *a, t_ilist *b)
{
	t_ilist_element	*a_element;
	t_ilist_element	*b_element;
	bool			checked_head;

	checked_head = false;
	a_element = a->head;
	while (a_element != a->head || !checked_head)
	{
		checked_head = true;
		b_element = b->head;
		while (b_element != b->tail)
		{
			if (b_element->i > a_element->i)
				return (false);
			b_element = b_element->next;
		}
		if (b->tail->i > a_element->i)
			return (false);
		a_element = a_element->next;
	}
	return (true);
}

t_slist	quick_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist			required_instructions;
	t_ilist_element	*pivot;

	slist_initialize(&required_instructions);
	while (true)
	{
		pivot = get_pivot(&stacks->a);
		if (pivot == NULL)
		{
			if (!ilist_is_empty(&stacks->b))
			{
				stock_and_call(instructions, &required_instructions, "pa", stacks);
				continue ;
			}
			else
				break ;
		}
		//dprintf(2, "pivot = %i\n", pivot->i);
		while (pivot != stacks->a.head)
		{
			if (stacks->a.head->i < pivot->i)
				stock_and_call(instructions, &required_instructions, "pb", stacks);
			else if (ilist_is_globally_sort2(&stacks->a, false)
			&& ft_strcmp(get_rotate_dir_a(&stacks->a, pivot), "rra") == 0)
				while (pivot != stacks->a.head)
					stock_and_call(instructions, &required_instructions, "rra", stacks);
			else
				stock_and_call(instructions, &required_instructions, "ra", stacks);
			if (ilist_is_globally_sort2(&stacks->a, false)
			&& ilist_is_globally_sort2(&stacks->b, true)
			&& elements_are_greater(&stacks->a, &stacks->b))
			{
				finish_sorting_ordered_stacks(instructions, &required_instructions, stacks);
				return (required_instructions);
			}
		}
	}
	return (required_instructions);
}