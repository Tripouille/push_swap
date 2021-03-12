#include "options.h"

void	options_parse(t_option options[], char ***args)
{
	int		i;

	++*args;
	while (**args)
	{
		i = 0;
		if (***args != '-' || !(**args)[1])
			return ;
		while ((**args)[++i])
		{
			if (!options_contain(options, (**args)[i]))
				return ;
			option_activate(options, &i, args);
			if (i == -1)
				break ;
		}
		if (**args)
			++*args;
	}
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
