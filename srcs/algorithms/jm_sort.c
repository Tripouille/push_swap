#include "algorithms.h"


ssize_t	required_rotate_distance_to_number_in_range(t_stacks const *stacks, bool reverse, double min, double max)
{
	size_t				distance;
	t_ilist_element		*element;

	distance = 0;
	if (reverse)
	{
		element = stacks->a.tail;
		while (element != stacks->a.head)
		{
			if (element->i >= min && element->i <= max)
				return (distance + 1);
			distance += 1;
			element = element->prev;
		}
		if (element->i >= min && element->i <= max)
			return (distance + 1);
	}
	else
	{
		element = stacks->a.head;
		while (element != stacks->a.tail)
		{
			if (element->i >= min && element->i <= max)
				return (distance);
			distance += 1;
			element = element->next;
		}
		if (element->i >= min && element->i <= max)
			return (distance);
	}
	return (-1);
}

bool	put_closest_in_range_on_b(t_instruction_infos const instructions[], t_stacks *stacks,
									double const range[2], t_slist *required_instructions)
{
	ssize_t				r_length;
	ssize_t				rr_length;

	r_length = required_rotate_distance_to_number_in_range(stacks, false, range[0], range[1]);
	printf("r_length = %li\n", r_length);
	if (r_length == -1)
		return (false);
	rr_length = required_rotate_distance_to_number_in_range(stacks, true, range[0], range[1]);
	printf("rr_length = %li\n", rr_length);
	if (r_length < rr_length)
		while (r_length--)
			stock_and_call(instructions, required_instructions, "ra", stacks);
	else
		while (rr_length--)
			stock_and_call(instructions, required_instructions, "rra", stacks);
	stock_and_call(instructions, required_instructions, "pb", stacks);
	return (true);
}

t_slist	jm_sort(t_instruction_infos const instructions[], t_stacks *stacks)
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
	double step = delta / 10.0;
	printf("delta = %i\n", delta);
	ilist_show(&stacks->a, ' ');
	int i = 0;
	while (i < 10)
	{
		range[0] = lowest + step * i;
		range[1] = lowest + step * (i + 1);
		printf("segment %i = %f -> %f\n", i, range[0], range[1]);
		while (stacks->a.size > 0 && put_closest_in_range_on_b(instructions, stacks, range, &required_instructions))
			;
		++i;
		printf("print a\n");
		ilist_show(&stacks->a, ' ');
		printf("print b\n");
		ilist_show(&stacks->b, ' ');

	}

	return (required_instructions);
}