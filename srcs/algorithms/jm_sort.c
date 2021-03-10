#include "algorithms.h"

t_ilist_element	*get_element_in_range(t_stacks const *stacks, bool down, double min, double max)
{
	t_ilist_element		*element;

	if (down)
	{
		element = stacks->a.tail;
		while (element != stacks->a.head)
		{
			if (element->i >= min && element->i <= max)
				return (element);
			element = element->prev;
		}
		if (element->i >= min && element->i <= max)
			return (element);
	}
	else
	{
		element = stacks->a.head;
		while (element != stacks->a.tail)
		{
			if (element->i >= min && element->i <= max)
				return (element);
			element = element->next;
		}
		if (element->i >= min && element->i <= max)
			return (element);
	}
	return (NULL);
}

t_steps	simulate_required_setup_b(t_ilist *b, int a_element_value)
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
		return (get_r_lengths(b, get_biggest_below(b, a_element_value), b->head));
}

bool	put_closest_in_range_on_b(t_instruction_infos const instructions[], t_stacks *stacks,
									 t_slist *required_instructions, double const range[2])
{
	t_ilist_element		*up_element_in_range;
	t_ilist_element		*down_element_in_range;
	t_steps				up_steps_a;
	t_steps				down_steps_a;
	t_steps				up_steps_b;
	t_steps				down_steps_b;

	up_element_in_range = get_element_in_range(stacks, false, range[0], range[1]);
	if (up_element_in_range == NULL)
		return (false);
	down_element_in_range = get_element_in_range(stacks, true, range[0], range[1]);
	up_steps_a = get_r_lengths(&stacks->a, up_element_in_range, stacks->a.head);
	down_steps_a = get_r_lengths(&stacks->a, down_element_in_range, stacks->a.head);
	up_steps_b = simulate_required_setup_b(&stacks->b, up_element_in_range->i);
	down_steps_b = simulate_required_setup_b(&stacks->b, down_element_in_range->i);
	t_rotates up_rotates = get_best_rotates(&up_steps_a, &up_steps_b);
	t_rotates down_rotates = get_best_rotates(&down_steps_a, &down_steps_b);
	if (up_rotates.total < down_rotates.total)
		execute_rotates(instructions, stacks, required_instructions, &up_rotates);
	else
		execute_rotates(instructions, stacks, required_instructions, &down_rotates);
	stock_and_call(instructions, required_instructions, "pb", stacks);
	return (true);
}


static t_slist sort(t_instruction_infos const instructions[], t_stacks *stacks, double segment)
{
    t_slist			required_instructions;
	int				lowest;
	int				biggest;
	int				delta;
	double			range[2];

	slist_initialize(&required_instructions);
	lowest = ilist_get_smallest(&stacks->a)->i;
	biggest = ilist_get_biggest(&stacks->a)->i;
	delta = biggest - lowest;
	double step = delta / segment;

	int i = 0;
	while (i * step < delta)
	{
		range[0] = lowest + step * i;
		range[1] = lowest + step * (i + 1);
		while (stacks->a.size > 0 && put_closest_in_range_on_b(instructions, stacks, &required_instructions, range))
			;
        if (ilist_is_globally_sort2(&stacks->a, false))
        {
            finish_sorting_ordered_stacks(instructions, &required_instructions, stacks);
            break ;
        }
		++i;
	}
	return (required_instructions);
}


t_slist	jm_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
    t_stacks        stacks_copy;
    t_slist         best_result;
    t_slist         actual_result;
    size_t          segment;

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