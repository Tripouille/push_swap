#include "utils.h"

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	 ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	 ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}