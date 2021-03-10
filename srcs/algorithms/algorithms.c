#include "algorithms.h"

void	stock_and_call(t_instruction_infos const instructions[], t_slist *required_instructions,
						char const *name, t_stacks *stacks)
{
	slist_push(required_instructions, name);
	instructions_call(instructions, name, stacks);
}

t_ilist_element	*get_biggest_below(t_ilist *ilist, int value)
{
	t_ilist_element		*element;
	t_ilist_element		*result;

	if (ilist->head == NULL)
		return (NULL);
	result = NULL;
	element = ilist->head;
	while (element != ilist->tail)
	{
		if (element->i < value &&
		(result == NULL || element->i > result->i))
			result = element;
		element = element->next;
	}
	if (element->i < value &&
	(result == NULL || element->i > result->i))
		result = element;
	return (result);
}

void	finish_sorting_ordered_stacks(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks)
{
	t_steps			a_steps;
	t_steps			b_steps;
	t_rotates		best_rotates;

	if (ilist_is_empty(&stacks->b))
		put_smallest_top_a(instructions, required_instructions, stacks);
	else if (ilist_is_empty(&stacks->a))
	{
		put_smallest_bottom_b(instructions, required_instructions, stacks);
		while (!ilist_is_empty(&stacks->b))
			stock_and_call(instructions, required_instructions, "pa", stacks);
	}
	else
	{
		a_steps = get_r_lengths(&stacks->a, ilist_get_smallest(&stacks->a), stacks->a.head);
		b_steps = get_r_lengths(&stacks->b, ilist_get_smallest(&stacks->b), stacks->b.tail);
		best_rotates = get_best_rotates(&a_steps, &b_steps);
		execute_rotates(instructions, stacks, required_instructions, &best_rotates);
		while (!ilist_is_empty(&stacks->b))
			stock_and_call(instructions, required_instructions, "pa", stacks);
	}
}
