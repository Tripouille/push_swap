#include "algorithms.h"

void	stock_and_call(t_instruction_infos const instructions[], t_slist *required_instructions,
						char const *name, t_stacks *stacks)
{
	slist_push(required_instructions, name);
	instructions_call(instructions, name, stacks);
}

int			get_r_length(t_ilist *ilist, t_ilist_element *target)
{
	int					r_length;
	t_ilist_element		 *element;

	r_length = 0;
	element = ilist->head;
	while (element != target)
	{
		r_length += 1;
		element = element->next;
	}
	return (r_length);
}

char const	*get_rotate_dir_a(t_ilist *ilist, t_ilist_element *target)
{
	int						ra_length;
	int						rra_length;

	ra_length = get_r_length(ilist, target);
	rra_length = ilist_size(ilist) - ra_length;
	if (ra_length <= rra_length)
		return ("ra");
	return ("rra");
}

char const	*get_rotate_dir_b(t_ilist *ilist, t_ilist_element *target)
{
	int						rb_length;
	int						rrb_length;

	rb_length = get_r_length(ilist, target);
	rrb_length = ilist_size(ilist) - rb_length;
	if (rb_length <= rrb_length)
		return ("rb");
	return ("rrb");
}

void	put_smallest_top_a(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks)
{
	t_ilist_element		*smallest;
	char const			*rotate;

	smallest = ilist_get_smallest(&stacks->a);
	rotate = get_rotate_dir_a(&stacks->a, smallest);
	while (stacks->a.head != smallest)
		stock_and_call(instructions, required_instructions, rotate, stacks);
}

void	put_smallest_bottom_b(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks)
{
	t_ilist_element		*smallest;
	char const			*rotate;

	smallest = ilist_get_smallest(&stacks->b);
	rotate = get_rotate_dir_b(&stacks->b, smallest);
	while (stacks->b.tail != smallest)
		stock_and_call(instructions, required_instructions, rotate, stacks);
}

void	rotate_and_push_finish(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks)
{
	int				ra_length_in_a;
	int				ra_length_in_b;
	t_ilist_element	*smallest_in_a;
	t_ilist_element	*smallest_in_b;
	
	smallest_in_a = ilist_get_smallest(&stacks->a);
	smallest_in_b = ilist_get_smallest(&stacks->b);
	ra_length_in_a = get_r_length(&stacks->a, smallest_in_a);
	ra_length_in_b = get_r_length(&stacks->b, smallest_in_b->next);
	if (ft_max(ra_length_in_a, ra_length_in_b) < ft_max(ilist_size(&stacks->a)
	- ra_length_in_a, ilist_size(&stacks->b) - ra_length_in_b))
		//rotate_both_lists(instructions, required_instructions, stacks, smallest_in_a, smallest_in_b);
	{
		while (stacks->a.head != smallest_in_a && stacks->b.head != smallest_in_b)
			stock_and_call(instructions, required_instructions, "rr", stacks);
		while (stacks->a.head != smallest_in_a)
			stock_and_call(instructions, required_instructions, "ra", stacks);
		while (stacks->b.head != smallest_in_b->next)
			stock_and_call(instructions, required_instructions, "rb", stacks);
	}
	else
	{
		while (stacks->a.head != smallest_in_a && stacks->b.head != smallest_in_b)
			stock_and_call(instructions, required_instructions, "rrr", stacks);
		while (stacks->a.head != smallest_in_a)
			stock_and_call(instructions, required_instructions, "rra", stacks);
		while (stacks->b.head != smallest_in_b->next)
			stock_and_call(instructions, required_instructions, "rrb", stacks);

	}
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(instructions, required_instructions, "pa", stacks);
}

void	finish_sorting_ordered_stacks(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks)
{
	if (ilist_is_empty(&stacks->b))
		put_smallest_top_a(instructions, required_instructions, stacks);
	else if (ilist_is_empty(&stacks->a))
	{
		put_smallest_bottom_b(instructions, required_instructions, stacks);
		while (!ilist_is_empty(&stacks->b))
			stock_and_call(instructions, required_instructions, "pa", stacks);
	}
	else
		rotate_and_push_finish(instructions, required_instructions, stacks);
}