#include "options.h"

static void	option_set(t_option *option, char name, bool need_arg,
					char const *description)
{
	option->name = name;
	option->need_arg = need_arg;
	option->active = false;
	option->description = description;
}

void	options_initialize_push_swap(t_option options[])
{
	int		i;

	i = 0;
	option_set(options + i++, 'v', false,
		"verbose (displays stacks before each step)");
	option_set(options + i++, 'f', false,
		"film (same as verbose with animation)");
	option_set(options + i++, 'a', true,
		"algo (allows to choose the sorting algorithm)");
	option_set(options + i++, 'c', false,
		"color (colors the last instruction)");
	option_set(options + i++, 'b', false,
		"benchmark (shows the step numbers of each algorithm)");
	option_set(options + i++, 'h', false,
		"help (current option)");
	option_set(options + i++, 0, false, "");
}

bool	options_contain(t_option options[], char option_name)
{
	int		i;

	i = -1;
	while (options[++i].name)
		if (options[i].name == option_name)
			return (true);
	return (false);
}

t_option	*get_option(t_option options[], char option_name)
{
	int		i;

	i = -1;
	while (options[++i].name)
		if (options[i].name == option_name)
			return (options + i);
	return (NULL);
}
