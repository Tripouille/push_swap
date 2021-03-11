#include "options.h"

void	option_set(t_option *option, char name, bool need_arg)
{
	option->name = name;
	option->need_arg = need_arg;
	option->active = false;
}


void	options_initialize_checker(t_option options[])
{
	option_set(options + 0, 'v', false);
	option_set(options + 1, 'a', false);
	option_set(options + 2, 'f', true);
	option_set(options + 3, 0, false);
}

void	options_initialize_push_swap(t_option options[])
{
	option_set(options + 0, 'v', false);
	option_set(options + 1, 'a', false);
	option_set(options + 2, 'c', false);
	option_set(options + 3, 'f', true);
	option_set(options + 4, 'b', true);
	option_set(options + 5, 0, false);
}

bool	options_contain(t_option options[], char const option_name)
{
	int 		i;

	i = -1;
	while (options[++i].name)
		if (options[i].name == option_name)
			return (true);
	return (false);
}

void	option_activate(t_option options[], int *pos, char ***args)
{
	int 		i;

	i = -1;
	while (options[++i].name)
		if (options[i].name == (**args)[*pos])
		{
			options[i].active = true;
			if (options[i].need_arg)
			{
				if ((**args)[*pos + 1])
				{
					options[i].value = **args + *pos + 1;
					*pos = -1;
				}
				else
				{
					options[i].value = (*args)[1];
					*pos = -1;
					++*args;
				}
			}
			return ;
		}
}

