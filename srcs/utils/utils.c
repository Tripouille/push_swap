#include "utils.h"

void	errorExit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_strlen(char const *s)
{
	int	len;

	len = 0;
	while (*s++)
		++len;
	return (len);
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
