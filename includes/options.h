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
    char const      *description;
}				t_option;

void    options_initialize_push_swap(t_option options[]);
void    options_initialize_checker(t_option options[]);
bool        options_contain(t_option options[], char option_name);
t_option    *get_option(t_option options[], char option_name);

void	options_parse(t_option options[], char ***args);
void	option_activate(t_option options[], int *pos, char ***args);

#endif