#include "checker.h"

int	error(void)
{
	printf("Error\n");
	return (-1);
}

bool	is_valid_number(const char *s)
{
	int	i;

	if (ft_strcmp(s, "-2147483648") == 0)
		return (true);
	if (s[0] == '-')
		++s;
	if (*s == 0)
		return (false);
	if (ft_strlen(s) > 10)
		return (false);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (false);
	return (ft_strlen(s) < 9 || ft_strcmp(s, "2147483647") <= 0);
}

bool	get_numbers(char **args)
{
	int		i;
	int		nb;

	i = 0;
	while (args[++i] != NULL)
	{
		if (!is_valid_number(args[i]))
			return (false);
		nb = ft_atoi(args[i]);
		printf("%d\n", nb);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (get_numbers(argv) == false)
		return (error());
	return (0);
}
