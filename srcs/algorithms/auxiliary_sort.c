#include "algorithms.h"

/*t_slist	auxiliary_sort(t_instruction_infos instructions[], t_stacks *stacks)
{
	t_slist	instructionNames;

	slist_initialize(&instructionNames);
	while (!ilist_is_empty(&stacks->a))
	{
		putSmallestOnTop(instructions, &instructionNames, stacks);
		if (ilist_is_sort(&stacks->a, false))
			break ;
		stock_and_call(&instructionNames, instructions, "pb", stacks);
	}
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(&instructionNames, instructions, "pa", stacks);
	return (instructionNames);
}*/