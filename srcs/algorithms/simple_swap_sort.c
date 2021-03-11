#include "algorithms.h"

t_ilist_element	*get_unordered_element(t_ilist *a, int *distance, bool up,
											t_element_pair *smallest_biggest)
{
	t_ilist_element	*element;

	*distance = 0;
	element = a->head;
	while ((up && element != a->tail) || (!up && element != a->head->next))
	{
		if (element->i > element->next->i
			&& !(element == smallest_biggest->b
				&& element->next == smallest_biggest->a))
			break ;
		++*distance;
		if (up)
			element = element->next;
		else
			element = element->prev;
	}
	return (element);
}

t_ilist_element	*get_closest_unordered_element(t_ilist *a, char const **rotate,
	t_element_pair *small_big)
{
	t_ilist_element	*up_element;
	t_ilist_element	*down_element;
	int				up_distance;
	int				down_distance;

	up_element = get_unordered_element(a, &up_distance, true, small_big);
	down_element = get_unordered_element(a, &down_distance, false, small_big);
	if (up_distance <= down_distance)
	{
		*rotate = "ra";
		return (up_element);
	}
	else
	{
		*rotate = "rra";
		return (down_element);
	}
}

t_slist	simple_swap_sort(t_instruction_infos const instructions[],
							t_stacks *stacks)
{
	t_slist			required_instructions;
	t_ilist_element	*closest_unordered_element;
	t_element_pair	smallest_biggest;
	char const		*rotate;

	slist_initialize(&required_instructions);
	smallest_biggest.a = ilist_get_smallest(&stacks->a);
	smallest_biggest.b = ilist_get_biggest(&stacks->a);
	while (!ilist_is_globally_sort2(&stacks->a, false))
	{
		closest_unordered_element = get_closest_unordered_element(&stacks->a,
				&rotate, &smallest_biggest);
		while (closest_unordered_element != stacks->a.head)
			stock_and_call(instructions, &required_instructions, rotate,
				stacks);
		stock_and_call(instructions, &required_instructions, "sa", stacks);
	}
	put_smallest_top_a(instructions, &required_instructions, stacks);
	return (required_instructions);
}
