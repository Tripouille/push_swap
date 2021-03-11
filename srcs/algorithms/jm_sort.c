#include "algorithms.h"

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

static bool	put_closest_in_range_on_b(t_instruction_infos const instructions[],
			t_stacks *stacks, t_slist *r_instructions, double const range[2])
{
	t_ilist_element		*up_element;
	t_ilist_element		*down_element;
	t_steps				steps_a[2];
	t_steps				steps_b[2];
	t_rotates			rotates[2];

	up_element = get_element_in_range_up(stacks, range[0], range[1]);
	if (up_element == NULL)
		return (false);
	down_element = get_element_in_range_down(stacks, range[0], range[1]);
	steps_a[0] = get_r_lengths(&stacks->a, up_element, stacks->a.head);
	steps_a[1] = get_r_lengths(&stacks->a, down_element, stacks->a.head);
	steps_b[0] = simulate_required_setup_b(&stacks->b, up_element->i);
	steps_b[1] = simulate_required_setup_b(&stacks->b, down_element->i);
	rotates[0] = get_best_rotates(&steps_a[0], &steps_b[0]);
	rotates[1] = get_best_rotates(&steps_a[1], &steps_b[1]);
	if (rotates[0].total < rotates[1].total)
		execute_rotates(instructions, stacks, r_instructions, &rotates[0]);
	else
		execute_rotates(instructions, stacks, r_instructions, &rotates[1]);
	stock_and_call(instructions, r_instructions, "pb", stacks);
	return (true);
}

static t_slist	sort(t_instruction_infos const instructions[], t_stacks *stacks,
	double segment)
{
	t_slist			required_instructions;
	int				lowest;
	int				delta;
	double			range[2];
	int				i;

	slist_initialize(&required_instructions);
	lowest = ilist_get_smallest(&stacks->a)->i;
	delta = ilist_get_biggest(&stacks->a)->i - lowest;
	i = -1;
	while (++i < (int)segment)
	{
		range[0] = lowest + i * delta / segment;
		range[1] = lowest + (i + 1) * delta / segment;
		while (stacks->a.size > 0 && put_closest_in_range_on_b(instructions,
				stacks, &required_instructions, range))
			;
		if (ilist_is_globally_sort2(&stacks->a, false))
		{
			finish_sorting_ordered_stacks(instructions, &required_instructions,
				stacks);
			break ;
		}
	}
	return (required_instructions);
}

t_slist	jm_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_stacks	stacks_copy;
	t_slist		best_result;
	t_slist		actual_result;
	size_t		segment;

	slist_initialize(&best_result);
	segment = 0;
	while (++segment <= stacks->a.size)
	{
		stacks_copy = stacks_clone(stacks);
		if (stacks_copy.a.head == NULL)
			return (*slist_destroy(&best_result));
		actual_result = sort(instructions, &stacks_copy, segment);
		if (best_result.size == 0 || actual_result.size < best_result.size)
			*slist_destroy(&best_result) = actual_result;
		else
			slist_destroy(&actual_result);
		stacks_destroy(&stacks_copy);
	}
	return (best_result);
}
