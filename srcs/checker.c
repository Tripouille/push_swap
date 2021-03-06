#include "checker.h"

bool	check(void)
{
	return (false);
}

int	main(int argc, char **argv)
{
	t_ilist	a;
	t_ilist	b;

	if (argc == 1)
		return (0);
	ilist_initialize(&a);
	ilist_initialize(&b);
	get_numbers(argv, &a);
	ilist_destroy(&a);
	return (0);
}
