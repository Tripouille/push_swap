#include "algorithms.h"

char const	*get_rotate_dir_a(t_ilist *ilist, t_ilist_element *target)
{
	t_steps			steps;

	steps = get_r_lengths(ilist, target, ilist->head);
	if (steps.r <= steps.rr)
		return ("ra");
	return ("rra");
}

char const	*get_rotate_dir_b(t_ilist *ilist, t_ilist_element *target)
{
	t_steps			steps;

	steps = get_r_lengths(ilist, target, ilist->head);
	if (steps.r <= steps.rr)
		return ("rb");
	return ("rrb");
}
