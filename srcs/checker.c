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

bool	get_numbers(char **args, t_ilist *a)
{
	int		i;
	long	nb;

	i = 0;
	while (args[++i] != NULL)
	{
		if (!set_number(args[i], &nb) || ilist_contain(a, nb))
		{
			ilist_destroy(a);
			return (false);
		}
		ilist_push(a, nb);
	}
	ilist_show(*a, false);
	return (true);
}

bool	check(void)
{
	return (false);
}

int	main(int argc, char **argv)
{
	t_ilist	a;
	t_ilist	b;

	(void)argc;
	ilist_initialize(&a);
	ilist_initialize(&b);
	if (get_numbers(argv, &a) == false)
		return (error());
	ilist_destroy(&a);
	return (0);
}
