#include "utils.h"

void	errorExit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
