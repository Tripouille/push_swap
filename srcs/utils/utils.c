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

int	ft_strcmp(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_strcpy(char *dest, char const *source)
{
	int		i;

	i = -1;
	while (source[++i])
		dest[i] = source[i];
	dest[i] = 0;
}