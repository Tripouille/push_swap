#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

# include "list.h"

void	errorExit(void);
int		ft_strlen(char const *s);
bool	ft_isdigit(char c);

#endif
