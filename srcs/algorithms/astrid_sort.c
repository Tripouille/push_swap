#include "algorithms.h"

static void	put_smallest_on_top_and_swap(t_instruction_infos const \
	instructions[], t_slist *required_instructions, t_stacks *stacks)
{
	t_ilist_element		*smallest;
	char const			*rotate;

	smallest = ilist_get_smallest(&stacks->a);
	rotate = get_rotate_dir_a(&stacks->a, smallest);
	while (stacks->a.head != smallest)
	{
		if (stacks->a.head->i > stacks->a.head->next->i
			&& !ilist_is_globally_sort2(&stacks->a, false))
			stock_and_call(instructions, required_instructions, "sa", stacks);
		else
			stock_and_call(instructions, required_instructions, rotate, stacks);
	}
}

t_slist	astrid_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist	required_instructions;

	slist_initialize(&required_instructions);
	while (!ilist_is_empty(&stacks->a))
	{
		put_smallest_on_top_and_swap(instructions, &required_instructions,
			stacks);
		if (ilist_is_sort(&stacks->a, false))
			break ;
		stock_and_call(instructions, &required_instructions, "pb", stacks);
	}
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(instructions, &required_instructions, "pa", stacks);
	return (required_instructions);
}
