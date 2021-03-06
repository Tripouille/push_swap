#include "checker.h"

bool	check(t_ilist *a, t_ilist *b)
{
	if (ilist_size(b) > 0)
		return (false);
	return (ilist_is_sort(a, false));
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
	//get_instructions();
	//execute();
	if (check(&a, &b))
		printf("OK\n");
	else
		printf("KO\n");
	ilist_destroy(&a);
	return (0);
}
