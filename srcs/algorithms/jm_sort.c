#include "algorithms.h"

static bool	is_ready_to_finish(t_stacks *stacks)
{
	return (ilist_is_globally_sort2(&stacks->a, false)
		&& ilist_is_globally_sort2(&stacks->b, true)
		&& (stacks->a.size == 0 || stacks->b.size == 0
			|| ilist_get_smallest(&stacks->a)->i
			> ilist_get_biggest(&stacks->b)->i));
}

static t_steps	simulate_required_setup_b(t_ilist *b, int a_element_value)
{
	t_steps		result;

	result.r = 0;
	result.rr = 0;
	if (b->size < 2)
		return (result);
	else if (a_element_value > ilist_get_biggest(b)->i
		|| a_element_value < ilist_get_smallest(b)->i)
		return (get_r_lengths(b, ilist_get_smallest(b), b->tail));
	else
		return (get_r_lengths(b, get_biggest_below(b, a_element_value),
				b->head));
}

static void	put_on_b(t_instruction_infos const instructions[],
			t_stacks *stacks, t_slist *r_instructions)
{
	t_steps				steps_a;
	t_steps				steps_b;
	t_ilist_element		*element;
	t_rotates			actual_rotate;
	t_rotates			best_rotate;

	element = stacks->a.head;
	best_rotate.total = -1;
	while (element != stacks->a.tail)
	{
		steps_a = get_r_lengths(&stacks->a, element, stacks->a.head);
		steps_b = simulate_required_setup_b(&stacks->b, element->i);
		actual_rotate = get_best_rotates(&steps_a, &steps_b);
		if (actual_rotate.total < best_rotate.total || best_rotate.total == -1)
			best_rotate = actual_rotate;
		element = element->next;
	}
	steps_a = get_r_lengths(&stacks->a, element, stacks->a.head);
	steps_b = simulate_required_setup_b(&stacks->b, element->i);
	actual_rotate = get_best_rotates(&steps_a, &steps_b);
	if (actual_rotate.total < best_rotate.total || best_rotate.total == -1)
		best_rotate = actual_rotate;
	execute_rotates(instructions, stacks, r_instructions, &best_rotate);
	stock_and_call(instructions, r_instructions, "pb", stacks);
}

t_slist	jm_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist			required_instructions;

	slist_initialize(&required_instructions);
	while (!is_ready_to_finish(stacks))
		put_on_b(instructions, stacks, &required_instructions);
	finish_sorting_ordered_stacks(instructions, &required_instructions,
		stacks);
	return (required_instructions);
}
