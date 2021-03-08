#include "algorithms.h"

t_slist			selection_sort(t_instruction_infos instructions[], t_stacks *stacks)
{
	t_slist					required_ins;
	t_ilist_element			*smallest;
	char const 				*rotate_dir;

	slist_initialize(&required_ins);
	while (!ilist_is_empty(&stacks->a))
	{
		smallest = ilist_get_smallest(&stacks->a);
		rotate_dir = get_best_rotate_dir(stacks, smallest);
		while (stacks->a.head != smallest)
			stock_and_call(instructions, &required_ins, rotate_dir, stacks);
		if (ilist_is_sort(&stacks->a, false))
			break ;
		stock_and_call(instructions, &required_ins, "pb", stacks);
	}
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(instructions, &required_ins, "pa", stacks);
	return (required_ins);
}