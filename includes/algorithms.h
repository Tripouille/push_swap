#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "ilist.h"
# include "slist.h"
# include "instructions.h"
# include "stacks.h"

void		stock_and_call(t_instruction_infos const instructions[], t_slist *required_instructions,
							char const *name, t_stacks *stacks);
char const	*get_rotate_dir_a(t_ilist *ilist, t_ilist_element *target);
void		put_smallest_top_a(t_instruction_infos const instructions[],
							t_slist *required_instructions, t_stacks *stacks);
void		finish_sorting_ordered_stacks(t_instruction_infos const instructions[],
						t_slist *required_instructions, t_stacks *stacks);


t_slist		franky_sort(t_instruction_infos const instructions[], t_stacks *stacks);
t_slist		selection_sort(t_instruction_infos const instructions[], t_stacks *stacks);
t_slist		quick_sort(t_instruction_infos const instructions[], t_stacks *stacks);

#endif