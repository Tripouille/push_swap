#include "algorithms.h"

static t_ilist_element	*get_second_smallest(t_ilist *a,
											t_ilist_element *smallest)
{
	t_ilist_element	*element;
	t_ilist_element	*second_smallest;

	element = a->head;
	second_smallest = NULL;
	while (element != a->tail)
	{
		if (element != smallest
			&& (second_smallest == NULL || element->i < second_smallest->i))
			second_smallest = element;
		element = element->next;
	}
	if (element != smallest
		&& (second_smallest == NULL || element->i < second_smallest->i))
		second_smallest = element;
	return (second_smallest);
}

static void	put_smallest_on_top_and_swap(t_instruction_infos const \
	instructions[], t_slist *required_instructions, t_stacks *stacks)
{
	t_ilist_element		*smallest;
	t_ilist_element		*second_smallest;
	char const			*rotate;
	char const			*next_rotate;

	smallest = ilist_get_smallest(&stacks->a);
	second_smallest = get_second_smallest(&stacks->a, smallest);
	rotate = get_rotate_dir_a(&stacks->a, smallest);
	while (stacks->a.head != smallest)
	{
		next_rotate = get_rotate_dir_a(&stacks->a, second_smallest);
		if (ft_strcmp(rotate, "ra") == 0 && smallest == stacks->a.head->next
			&& ft_strcmp(next_rotate, "ra") != 0
			&& !ilist_is_globally_sort(&stacks->a, smallest))
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
