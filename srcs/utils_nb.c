int	ft_atoi(char const *s)
{
	unsigned long long	res;
	int					i;
	unsigned long long	mult;

	mult = 1;
	i = 0;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			mult *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return ((int)(res * mult));
}