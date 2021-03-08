#include "algorithms.h"

void	stock_and_call(t_instruction_infos const instructions[], t_slist *required_instructions,
						char const *name, t_stacks *stacks)
{
	slist_push(required_instructions, name);
	instructions_call(instructions, name, stacks);
}

char const	*get_best_rotate_dir(t_stacks *stacks, t_ilist_element *target)
{
	int						ra_length;
	int						rra_length;
	t_ilist_element		 	*element;

	ra_length = 0;
	element = stacks->a.head;
	while (element != target)
	{
		element = element->next;
		ra_length += 1;
	}
	rra_length = ilist_size(&stacks->a) - ra_length;
	if (ra_length <= rra_length)
		return ("ra");
	return ("rra");
}