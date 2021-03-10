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

static bool	is_smaller_than_above(t_ilist_element *base_element, t_ilist *b)
{
	t_ilist_element *element;

	element = base_element->prev;
	while (element != b->head)
	{
		if (element->i < base_element->i)
			return (false);
		element = element->prev;
	}
	return (base_element->i < b->head->i);
}

static t_ilist_element*	get_pivot_a(t_ilist *a)
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

static t_ilist_element*	get_pivot_b(t_ilist *b)
{
	t_ilist_element	*element;

	element = b->tail;
	while (element != b->head)
	{
		if (!is_smaller_than_above(element, b))
			return (element);
		element = element->prev;
	}
	return (NULL);
}

static bool	elements_are_greater(t_ilist *a, t_ilist *b)
{
	t_ilist_element	*a_element;
	t_ilist_element	*b_element;
	bool			head_was_checked;

	if (ilist_is_empty(a) || ilist_is_empty(b))
		return (true);
	head_was_checked = false;
	a_element = a->head;
	while (a_element != a->head || !head_was_checked)
	{
		head_was_checked = true;
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

static bool	is_ready_to_finish(t_stacks *stacks)
{
	return (ilist_is_globally_sort2(&stacks->a, false)
			&& ilist_is_globally_sort2(&stacks->b, true)
			&& elements_are_greater(&stacks->a, &stacks->b));
}

t_slist	quick_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist			required_instructions;
	t_ilist_element	*pivot_a;
	t_ilist_element	*pivot_b;

	slist_initialize(&required_instructions);
	while (true)
	{
		while (!ilist_is_sort(&stacks->a, false))
		{
			if (is_ready_to_finish(stacks))
			{
				finish_sorting_ordered_stacks(instructions, &required_instructions, stacks);
				return (required_instructions);
			}
			if (ilist_is_globally_sort2(&stacks->a, false))
			{
				put_smallest_top_a(instructions, &required_instructions, stacks);
				break ;
			}
			pivot_a = get_pivot_a(&stacks->a);
			if (stacks->a.head->i < pivot_a->i)
				stock_and_call(instructions, &required_instructions, "pb", stacks);
			else
				stock_and_call(instructions, &required_instructions, "ra", stacks);
		}
		while (ilist_is_sort(&stacks->a, false))
		{
			if (is_ready_to_finish(stacks))
			{
				finish_sorting_ordered_stacks(instructions, &required_instructions, stacks);
				return (required_instructions);
			}
			pivot_b = get_pivot_b(&stacks->b);
			if (pivot_b == NULL)
				stock_and_call(instructions, &required_instructions, "pa", stacks);
			else if (stacks->b.head->i < pivot_b->i)
				stock_and_call(instructions, &required_instructions, "rb", stacks);
			else
				stock_and_call(instructions, &required_instructions, "pa", stacks);
		}
	}
	return (required_instructions);
}