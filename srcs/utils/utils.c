#include "utils.h"

void	error(void)
{
	write(2, "Error\n", 6);
}

void	errorExit(void)
{
	error();
	exit(EXIT_FAILURE);
}
