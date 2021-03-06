#include "checker.h"

bool	check(void)
{
	return (false);
}

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;

	if (argc == 1)
		return (0);
	list_initialize(&a);
	list_initialize(&b);
	get_numbers(argv, &a);
	list_destroy(&a);
	return (0);
}
