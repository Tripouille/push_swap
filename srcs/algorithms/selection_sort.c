#include "algorithms.h"

t_slist			selection_sort(t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist					required_ins;

	slist_initialize(&required_ins);
	while (!ilist_is_empty(&stacks->a))
	{
		put_smallest_top_a(instructions, &required_ins, stacks);
		if (ilist_is_sort(&stacks->a, false))
			break ;
		stock_and_call(instructions, &required_ins, "pb", stacks);
	}
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(instructions, &required_ins, "pa", stacks);
	return (required_ins);
}