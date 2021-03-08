#include "algorithms.h"

void	putSmallestOnTop(t_instruction_infos instructions[], t_slist *instructionNames, t_stacks *stacks)
{
	t_ilist_element		 *smallest;
	int						ra_length;
	int						rra_length;
	char const				*rotate;
	t_ilist_element		 *element;

	smallest = ilist_get_smallest(&stacks->a);
	element = stacks->a.head;
	ra_length = 0;
	while (element != smallest)
	{
		element = element->next;
		ra_length += 1;
	}
	rra_length = ilist_size(&stacks->a) - ra_length;
	if (ra_length <= rra_length)
		rotate = "ra";
	else
		rotate = "rra";
	while (stacks->a.head != smallest)
	{
		if (stacks->a.head->i > stacks->a.head->next->i && !ilist_is_globally_sort(&stacks->a, smallest))
			stock_and_call(instructions, instructionNames, "sa", stacks);
		else
			stock_and_call(instructions, instructionNames, rotate, stacks);
	}
}

t_slist	franky_sort(t_instruction_infos instructions[], t_stacks *stacks)
{
	t_slist	instructionNames;
	slist_initialize(&instructionNames);
	while (!ilist_is_empty(&stacks->a))
	{
		putSmallestOnTop(instructions, &instructionNames, stacks);
		if (ilist_is_sort(&stacks->a, false))
			break ;
		stock_and_call(instructions, &instructionNames, "pb", stacks);
	}
	while (!ilist_is_empty(&stacks->b))
		stock_and_call(instructions, &instructionNames, "pa", stacks);
	return (instructionNames);
}