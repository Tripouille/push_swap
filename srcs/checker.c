#include "checker.h"

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (-1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		write(1, "OK", 2);
		return (0);
	}
	return (0);
}
