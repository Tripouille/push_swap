#include "checker.h"

int	error(void)
{
	printf("Error\n");
	return (-1);
}

bool	set_number(const char *s, long *nb)
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
	while (ft_isdigit(s[++i]) && -*nb >= INT_MIN)
		*nb = *nb * 10 + s[i] - '0';
	if (isNegative)
		*nb = -*nb;
	if (s[i] || *nb > INT_MAX || *nb < INT_MIN)
		return (false);
	return (true);
}

bool	get_numbers(char **args)
{
	int		i;
	long	nb;

	i = 0;
	while (args[++i] != NULL)
	{
		if (!set_number(args[i], &nb))
			return (false);
		printf("%ld\n", nb);
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
