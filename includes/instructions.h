#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "stacks.h"
# include "utils.h"

typedef void	(*t_instruction)(t_stacks *stacks);

typedef struct s_instruction_infos
{
	char			name[4];
	t_instruction	funtion;
}					t_instruction_infos;



void	instructions_set(t_instruction_infos *instruction_infos, char *name,
						t_instruction function);
void	instructions_init(t_instruction_infos instructions[]);
void	instructions_call(t_instruction_infos const instructions[], char const *name,
							t_stacks *stacks);
bool	instructions_contain(t_instruction_infos const instructions[], char *name);

void	instructions_swap_a(t_stacks *stacks);
void	instructions_swap_b(t_stacks *stacks);
void	instructions_swap_ab(t_stacks *stacks);

void	instructions_push_a(t_stacks *stacks);
void	instructions_push_b(t_stacks *stacks);

void	instructions_rotate_a(t_stacks *stacks);
void	instructions_rotate_b(t_stacks *stacks);
void	instructions_rotate_ab(t_stacks *stacks);

void	instructions_reverse_rotate_a(t_stacks *stacks);
void	instructions_reverse_rotate_b(t_stacks *stacks);
void	instructions_reverse_rotate_ab(t_stacks *stacks);

#endif
