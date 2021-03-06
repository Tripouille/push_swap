#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

# include "ilist.h"

void	get_numbers(char **args, t_ilist *a);

void	errorExit(void);
int		ft_strlen(char const *s);
bool	ft_isdigit(char c);

#endif
