#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "ilist.h"
# include "slist.h"
# include "instructions.h"
# include "stacks.h"

typedef struct s_steps
{
	int			r;
	int			rr;
}				t_steps;


void		stock_and_call(t_instruction_infos const instructions[], t_slist *required_instructions,
							char const *name, t_stacks *stacks);
t_steps		get_r_lengths(t_ilist *ilist, t_ilist_element *src, t_ilist_element *dst);
char const	*get_rotate_dir_a(t_ilist *ilist, t_ilist_element *target);
t_ilist_element	*get_biggest_below(t_ilist *ilist, int value);
void	    put_target_on_top_b(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks,
							t_ilist_element *target);
void		put_smallest_top_a(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks);
void	    put_smallest_top_b(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks);
void		put_smallest_bottom_b(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks);
void		finish_sorting_ordered_stacks(t_instruction_infos const instructions[],
						t_slist *required_instructions, t_stacks *stacks);


t_slist		franky_sort(t_instruction_infos const instructions[], t_stacks *stacks);
t_slist		selection_sort(t_instruction_infos const instructions[], t_stacks *stacks);
t_slist		quick_sort(t_instruction_infos const instructions[], t_stacks *stacks);
t_slist		jm_sort(t_instruction_infos const instructions[], t_stacks *stacks);


#endif