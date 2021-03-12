#include "options.h"

void	option_set(t_option *option, char name, bool need_arg)
{
	option->name = name;
	option->need_arg = need_arg;
	option->active = false;
}


void	options_initialize_checker(t_option options[])
{
    int     i;

    i = 0;
	option_set(options + i++, 'v', false);
	option_set(options + i++, 'f', false);
	option_set(options + i++, 'h', false);
	option_set(options + i++, 0, false);
}

void	options_initialize_push_swap(t_option options[])
{
    int     i;

    i = 0;
	option_set(options + i++, 'v', false);
	option_set(options + i++, 'f', false);
	option_set(options + i++, 'a', true);
	option_set(options + i++, 'c', false);
	option_set(options + i++, 'b', false);
	option_set(options + i++, 'h', false);
	option_set(options + i++, 0, false);
}

bool	options_contain(t_option options[], char option_name)
{
	int 		i;

	i = -1;
	while (options[++i].name)
		if (options[i].name == option_name)
			return (true);
	return (false);
}

t_option    *get_option(t_option options[], char option_name)
{
   	int 		i;

	i = -1;
	while (options[++i].name)
		if (options[i].name == option_name)
			return (options + i);
	return (NULL); 
}