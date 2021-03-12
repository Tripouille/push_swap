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
