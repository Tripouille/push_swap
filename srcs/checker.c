#include "checker.h"

int	error(void)
{
	printf("Error\n");
	return (-1);
}

bool	is_valid_number(char *s)
{
	(void)s;
	return (true);
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
