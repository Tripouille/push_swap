#ifndef OPTIONS_H
#define OPTIONS_H
# include <stdbool.h>
# include "utils.h"

typedef struct s_option
{
	char			name;
	bool			active;
	bool			need_arg;
	char const		*value;
}				t_option;

void	option_set(t_option *option, char name, bool need_arg);
void	options_initialize_push_swap(t_option options[]);
void	options_initialize_checker(t_option options[]);
bool	options_contain(t_option options[], char const option_name);
void	option_activate(t_option options[], int *pos, char ***args);

void	options_parse(t_option options[], char ***args);

#endif