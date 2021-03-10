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

int	 ft_min_3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c)
		return (b);
	return (c);
}

int	 ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}