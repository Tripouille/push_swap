#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "ilist.h"
# include "instructions.h"

bool	get_numbers(char **args, t_ilist *a);

void	errorExit(void);
int		ft_strlen(char const *s);
int		ft_strcmp(char const *s1, char const *s2);
bool	ft_isdigit(char c);
void	ft_strcpy(char *dest, char const *source);

#endif
