#include "utils.h"

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

void	ft_strcpy(char *dest, char const *source)
{
	int		i;

	i = -1;
	while (source[++i])
		dest[i] = source[i];
	dest[i] = 0;
}

void	ft_putstr_fd(int fd, char const *s)
{
	write(fd, s, ft_strlen(s));
}