#include "algorithms.h"

t_steps	get_r_lengths(t_ilist *ilist, t_ilist_element *src,
						t_ilist_element *dst)
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

static void	set_rotate_details(t_rotates *rotates, t_steps *max_steps,
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
	opposite_steps = ft_min(a_steps->r, a_steps->rr)
		+ ft_min(b_steps->r, b_steps->rr);
	rotates.total = ft_min_3(max_steps.r, max_steps.rr, opposite_steps);
	set_rotate_details(&rotates, &max_steps, a_steps, b_steps);
	return (rotates);
}

void	execute_rotates(t_instruction_infos const instructions[],
		t_stacks *stacks, t_slist *required_instructions, t_rotates *rotates)
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
