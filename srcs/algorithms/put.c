#include "algorithms.h"

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
