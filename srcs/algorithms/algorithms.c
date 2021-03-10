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

t_steps	get_r_lengths(t_ilist *ilist, t_ilist_element *src, t_ilist_element *dst)
{
	t_steps				steps;
	t_ilist_element		*element;
	
	steps.r = 0;
	steps.rr = 0;
	if (src == dst)
		return (steps);
	element = src;
	while (element != dst)
	{
		steps.r += 1;
		element = element->prev;
	}
	steps.rr = ilist->size - steps.r;
	return (steps);
}

static void	rotates_initialize(t_rotates *rotates)
{
	rotates->ra = 0;
	rotates->rb = 0;
	rotates->rr = 0;
	rotates->rra = 0;
	rotates->rrb = 0;
	rotates->rrr = 0;
}

static void	set_rotate_details(t_rotates*rotates, t_steps *max_steps,
								t_steps *a_steps, t_steps *b_steps)
{
	if (rotates->total == max_steps->r)
	{
		rotates->rr = ft_min(a_steps->r, b_steps->r);
		rotates->ra = a_steps->r - rotates->rr;
		rotates->rb = b_steps->r - rotates->rr;
	}
	else if (rotates->total == max_steps->rr)
	{
		rotates->rrr = ft_min(a_steps->rr, b_steps->rr);
		rotates->rra = a_steps->rr - rotates->rrr;
		rotates->rrb = b_steps->rr - rotates->rrr;
	}
	else if (a_steps->r < a_steps->rr)
	{
		rotates->ra = a_steps->r;
		rotates->rrb = b_steps->rr;
	}
	else
	{
		rotates->rra = a_steps->rr;
		rotates->rb = b_steps->r;
	}
}

t_rotates	get_best_rotates(t_steps *a_steps, t_steps *b_steps)
{
	t_rotates	rotates;
	t_steps		max_steps;
	int			opposite_steps;

	rotates_initialize(&rotates);
	max_steps.r = ft_max(a_steps->r, b_steps->r);
	max_steps.rr = ft_max(a_steps->rr, b_steps->rr);
	opposite_steps = ft_min(a_steps->r, a_steps->rr) + ft_min(b_steps->r, b_steps->rr);
	rotates.total = ft_min_3(max_steps.r, max_steps.rr, opposite_steps);
	set_rotate_details(&rotates, &max_steps, a_steps, b_steps);
	return (rotates);
}

char const	*get_rotate_dir_a(t_ilist *ilist, t_ilist_element *target)
{
	int						ra_length;
	int						rra_length;

	ra_length = get_r_length(ilist, target);
	rra_length = ilist->size - ra_length;
	if (ra_length <= rra_length)
		return ("ra");
	return ("rra");
}

char const	*get_rotate_dir_b(t_ilist *ilist, t_ilist_element *target)
{
	int						rb_length;
	int						rrb_length;

	rb_length = get_r_length(ilist, target);
	rrb_length = ilist->size - rb_length;
	if (rb_length <= rrb_length)
		return ("rb");
	return ("rrb");
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

void	put_smallest_top_b(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks)
{
	t_ilist_element		*smallest;
	char const			*rotate;

	smallest = ilist_get_smallest(&stacks->b);
	rotate = get_rotate_dir_b(&stacks->b, smallest);
	while (stacks->b.head != smallest)
		stock_and_call(instructions, required_instructions, rotate, stacks);
}

void	put_target_on_top_b(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks,
							t_ilist_element *target)
{
	char const			*rotate;

	rotate = get_rotate_dir_b(&stacks->b, target);
	while (stacks->b.head != target)
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
	int				ra_length;
	int				rb_length;
	t_ilist_element	*smallest_in_a;
	t_ilist_element	*smallest_in_b;

	smallest_in_a = ilist_get_smallest(&stacks->a);
	smallest_in_b = ilist_get_smallest(&stacks->b);
	ra_length = get_r_length(&stacks->a, smallest_in_a);
	rb_length = get_r_length(&stacks->b, smallest_in_b->next);
	if (ft_max(ra_length, rb_length) < ft_max(stacks->a.size - ra_length, stacks->b.size - rb_length)) //prendre aussi le cas min(2 sens opposés)
	{
		while (stacks->a.head != smallest_in_a && stacks->b.tail != smallest_in_b)
			stock_and_call(instructions, required_instructions, "rr", stacks);
		while (stacks->a.head != smallest_in_a)
			stock_and_call(instructions, required_instructions, "ra", stacks);
		while (stacks->b.tail != smallest_in_b)
			stock_and_call(instructions, required_instructions, "rb", stacks);
	}
	else
	{
		while (stacks->a.head != smallest_in_a && stacks->b.tail != smallest_in_b)
			stock_and_call(instructions, required_instructions, "rrr", stacks);
		while (stacks->a.head != smallest_in_a)
			stock_and_call(instructions, required_instructions, "rra", stacks);
		while (stacks->b.tail != smallest_in_b)
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

void	execute_rotates(t_instruction_infos const instructions[], t_stacks *stacks,
									 t_slist *required_instructions, t_rotates *rotates)
{
	while (rotates->ra--)
		stock_and_call(instructions, required_instructions, "ra", stacks);
	while (rotates->rb--)
		stock_and_call(instructions, required_instructions, "rb", stacks);
	while (rotates->rr--)
		stock_and_call(instructions, required_instructions, "rr", stacks);
	while (rotates->rra--)
		stock_and_call(instructions, required_instructions, "rra", stacks);
	while (rotates->rrb--)
		stock_and_call(instructions, required_instructions, "rrb", stacks);
	while (rotates->rrr--)
		stock_and_call(instructions, required_instructions, "rrr", stacks);
}