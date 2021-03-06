#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "ilist.h"
# include "utils.h"

typedef void (*instruction)(t_ilist *a, t_ilist *b);

typedef struct      s_instruction_infos
{
	char          name[4];
	instruction   funtion;
}                   t_instruction_infos;

void    instructions_set(t_instruction_infos *instruction_infos, char *name,
						instruction function);
void    instructions_init(t_instruction_infos instructions[]);
void    instructions_call(t_instruction_infos const instructions[], char const *name,
							t_ilist *a, t_ilist *b);
bool    instructions_contain(t_instruction_infos const instructions[], char *name);
void	instructions_destroy_ab(t_ilist *a, t_ilist *b);


void	instructions_swap_a(t_ilist *a, t_ilist *b);
void	instructions_swap_b(t_ilist *a, t_ilist *b);
void	instructions_swap_ab(t_ilist *a, t_ilist *b);

void	instructions_push_a(t_ilist *a, t_ilist *b);
void	instructions_push_b(t_ilist *a, t_ilist *b);

void	instructions_rotate_a(t_ilist *a, t_ilist *b);
void	instructions_rotate_b(t_ilist *a, t_ilist *b);
void	instructions_rotate_ab(t_ilist *a, t_ilist *b);

void	instructions_reverse_rotate_a(t_ilist *a, t_ilist *b);
void	instructions_reverse_rotate_b(t_ilist *a, t_ilist *b);
void	instructions_reverse_rotate_ab(t_ilist *a, t_ilist *b);

#endif
