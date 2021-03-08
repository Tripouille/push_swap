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
		element = element->next;
		r_length += 1;
	}
	return (r_length);
}

char const	*get_best_rotate_dir(t_stacks *stacks, t_ilist_element *target)
{
	int						ra_length;
	int						rra_length;

	ra_length = get_r_length(&stacks->a, target);
	rra_length = ilist_size(&stacks->a) - ra_length;
	if (ra_length <= rra_length)
		return ("ra");
	return ("rra");
}

void	push_a_in_order(t_instruction_infos const instructions[],
						t_slist *required_instructions, t_stacks *stacks)
{
	int				ra_length_in_a;
	int				ra_length_in_b;
	t_ilist_element	*smallest_in_a;
	t_ilist_element	*smallest_in_b;
	int				index;

	smallest_in_a = ilist_get_smallest(&stacks->a);
	smallest_in_b = ilist_get_smallest(&stacks->b);
	ra_length_in_a = get_r_length(&stacks->a, smallest_in_a);
	ra_length_in_b = get_r_length(&stacks->b, smallest_in_b->next);
	if (ft_max(ra_length_in_a, ra_length_in_b) < ft_max(ilist_size(&stacks->a)
	- ra_length_in_a, ilist_size(&stacks->b) - ra_length_in_b))
		index = RA;
	else
		index = RRA;
	while (stacks->a.head != smallest_in_a && stacks->b.head != smallest_in_b)
		stock_and_call(instructions, required_instructions, instructions[index + 2].name, stacks);
	while (stacks->a.head != smallest_in_a)
		stock_and_call(instructions, required_instructions, instructions[index].name, stacks);
	while (stacks->b.head != smallest_in_b->next)
		stock_and_call(instructions, required_instructions, instructions[index + 1].name, stacks);
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(instructions, required_instructions, "pa", stacks);
}