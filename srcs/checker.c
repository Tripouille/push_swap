#include "checker.h"

bool	is_valid_instruction(char *s)
{
	(void)s;
	return (true);
}

bool	get_instructions(t_slist *instructions)
{
	int		i;
	char	buffer[4];

	i = 0;
	while (read(0, buffer + i, 1) == 1)
	{
		if (i == 3 && buffer[i] != '\n')
			return (false);
		else if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			if (!is_valid_instruction(buffer))
				return (false);
			slist_push(instructions, buffer);
			i = 0;
		}
		else
			++i;
	}
	return (i == 0);
}

bool	check(t_ilist *a, t_ilist *b)
{
	if (ilist_size(b) > 0)
		return (false);
	return (ilist_is_sort(a, false));
}

void	destroy_lists(t_ilist *a, t_ilist *b, t_slist *instructions)
{
	ilist_destroy(a);
	ilist_destroy(b);
	slist_destroy(instructions);
}

int	main(int argc, char **argv)
{
	t_ilist	a;
	t_ilist	b;
	t_slist instructions;

	if (argc == 1)
		return (0);
	ilist_initialize(&a);
	ilist_initialize(&b);
	get_numbers(argv, &a);
	slist_initialize(&instructions);
	if (!get_instructions(&instructions))
	{
		destroy_lists(&a, &b, &instructions);
		errorExit();
	}
	slist_show(instructions, false);
	//execute();
	if (check(&a, &b))
		printf("OK\n");
	else
		printf("KO\n");
	destroy_lists(&a, &b, &instructions);
	return (0);
}
