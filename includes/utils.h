#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "ilist.h"

typedef void (*instruction)(t_ilist *a, t_ilist *b);

typedef struct      s_instruction_infos
{
	char          name[4];
	instruction   funtion;
}                   t_instruction_infos;

void	get_numbers(char **args, t_ilist *a);

void	errorExit(void);
int		ft_strlen(char const *s);
int		ft_strcmp(char const *s1, char const *s2);
bool	ft_isdigit(char c);
void	ft_strcpy(char *dest, char const *source);


void    instructions_set(t_instruction_infos *instruction_infos, char *name,
						instruction function);
void    instructions_init(t_instruction_infos instructions[]);
void    instructions_call(t_instruction_infos const instructions[], char *name,
							t_ilist *a, t_ilist *b);
bool    instructions_contain(t_instruction_infos const instructions[], char *name);

#endif
