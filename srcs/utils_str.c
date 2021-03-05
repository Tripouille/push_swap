int	ft_strlen(char const *s)
{
	int	len;

	len = 0;
	while (s++)
		++len;
	return (len);
}
