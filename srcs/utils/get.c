#include "utils.h"

static bool	set_number(const char *s, long *nb)
{
	int		i;
	bool	isNegative;

	isNegative = false;
	if (s[0] == '-')
	{
		isNegative = true;
		++s;
	}
	if (s[0] == 0)
		return (false);
	*nb = 0;
	i = -1;
	while (ft_isdigit(s[++i]) && -(*nb) >= INT_MIN)
		*nb = *nb * 10 + s[i] - '0';
	if (isNegative)
		*nb = -(*nb);
	if (s[i] || *nb > INT_MAX || *nb < INT_MIN)
		return (false);
	return (true);
}

bool	get_numbers(char **args, t_ilist *a)
{
	int		i;
	long	nb;

	i = 0;
	while (args[++i] != NULL)
	{
		if (!set_number(args[i], &nb) || ilist_contain(a, nb))
			return (false);
		if (ilist_push(a, nb) == NULL)
			return (false);
	}
	return (true);
}

bool	get_instructions(t_slist *instructionNames,
							t_instruction_infos instructions[])
{
	int		i;
	char	buffer[4];

	i = 0;
	while (read(0, buffer + i, 1) == 1)
	{
		if (i == 3 && buffer[i] != '\n')
			return (false);
		else if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			if (!instructions_contain(instructions, buffer))
				return (false);
			if (slist_push(instructionNames, buffer) == NULL)
				return (false);
			i = 0;
		}
		else
			++i;
	}
	return (i == 0);
}
