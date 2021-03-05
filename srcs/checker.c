#include "checker.h"

int	error(void)
{
	write(2, "Error\n", 6);
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

bool	get_numbers(char **args, t_list *a)
{
	int		i;
	long	nb;

	i = 0;
	while (args[++i] != NULL)
	{
		if (!set_number(args[i], &nb) || list_contain(a, nb))
		{
			list_destroy(a);
			return (false);
		}
		list_push(a, nb);
	}
	list_show(*a, false);
	return (true);
}

bool	check(void)
{
	return (false);
}

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;

	(void)argc;
	list_initialize(&a);
	list_initialize(&b);
	if (get_numbers(argv, &a) == false)
		return (error());
	list_destroy(&a);
	return (0);
}
