#include "checker.h"

bool	get_instructions(t_slist *instructionNames, t_instruction_infos instructions[])
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
			if (!instructions_contain(instructions, buffer))
				return (false);
			slist_push(instructionNames, buffer);
			i = 0;
		}
		else
			++i;
	}
	return (i == 0);
}

void	execute(t_slist *instructionNames, t_instruction_infos instructions[], t_ilist *a, t_ilist *b)
{
	t_slist_element	*i;

	i = instructionNames->head;
	while (i != instructionNames->tail)
	{
		instructions_call(instructions, i->s, a, b);
		i = i->next;
	}
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
	t_ilist				a;
	t_ilist				b;
	t_slist				instructionNames;
	t_instruction_infos	instructions[12];

	if (argc == 1)
		return (0);
	ilist_initialize(&a);
	ilist_initialize(&b);
	get_numbers(argv, &a);
	slist_initialize(&instructionNames);
	instructions_init(instructions);
	if (!get_instructions(&instructionNames, instructions))
	{
		destroy_lists(&a, &b, &instructionNames);
		errorExit();
	}
	slist_show(instructionNames, false);
	execute(&instructionNames, instructions, &a, &b);
	if (check(&a, &b))
		printf("OK\n");
	else
		printf("KO\n");
	printf("list after execute :\n"); ilist_show(a, false);
	destroy_lists(&a, &b, &instructionNames);
	return (0);
}
