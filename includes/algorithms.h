#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "ilist.h"
# include "slist.h"
# include "instructions.h"
# include "stacks.h"

typedef struct s_steps
{
	int		r;
	int		rr;
}			t_steps;

typedef struct s_rotates
{
	int		rr;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}			t_rotates;

typedef struct s_element_pair
{
	t_ilist_element	*a;
	t_ilist_element	*b;
}					t_element_pair;

void			stock_and_call(t_instruction_infos const instructions[],
					t_slist *required_instructions,
					char const *name, t_stacks *stacks);
t_ilist_element	*get_biggest_below(t_ilist *ilist, int value);
void			finish_sorting_ordered_stacks(t_instruction_infos const \
					instructions[], \
					t_slist *required_instructions, t_stacks *stacks);
t_ilist_element	*get_element_in_range_up(t_stacks const *stacks, \
	double min, double max);
t_ilist_element	*get_element_in_range_down(t_stacks const *stacks, \
	double min, double max);

t_steps			get_r_lengths(t_ilist *ilist, t_ilist_element *src,
					t_ilist_element *dst);
t_rotates		get_best_rotates(t_steps *a_steps, t_steps *b_steps);
void			execute_rotates(t_instruction_infos const instructions[], \
					t_stacks *stacks, t_slist *required_instructions, \
					t_rotates *rotates);

char const		*get_rotate_dir_a(t_ilist *ilist, t_ilist_element *target);
char const		*get_rotate_dir_b(t_ilist *ilist, t_ilist_element *target);

void			put_target_on_top_b(t_instruction_infos const instructions[],
					t_slist *required_instructions, t_stacks *stacks,
					t_ilist_element *target);
void			put_smallest_top_a(t_instruction_infos const instructions[], \
					t_slist *required_instructions, t_stacks *stacks);
void			put_smallest_top_b(t_instruction_infos const instructions[], \
					t_slist *required_instructions, t_stacks *stacks);
void			put_smallest_bottom_b(t_instruction_infos const instructions[], \
					t_slist *required_instructions, t_stacks *stacks);

t_slist			astrid_sort(t_instruction_infos const instructions[], \
					t_stacks *stacks);
t_slist			selection_sort(t_instruction_infos const instructions[], \
					t_stacks *stacks);
t_slist			jm_sort(t_instruction_infos const instructions[], \
					t_stacks *stacks);
t_slist			simple_swap_sort(t_instruction_infos const instructions[], \
					t_stacks *stacks);

#endif