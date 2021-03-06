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
			if (slist_push(instructionNames, buffer) == NULL)
				return (false);
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
	if (instructionNames->tail != NULL)
		instructions_call(instructions, instructionNames->tail->s, a, b);
}

void	printResult(t_ilist *a, t_ilist *b)
{
	if (ilist_is_empty(b) && ilist_is_sort(a, false))
		printf("OK\n");
	else
		printf("KO\n");
}

void	destroy_lists(t_ilist *a, t_ilist *b, t_slist *instructions)
{
	ilist_destroy(a);
	ilist_destroy(b);
	slist_destroy(instructions);
}

static void	initialize(t_ilist *a, t_ilist *b, t_slist *instructionNames, t_instruction_infos instructions[])
{
	ilist_initialize(a);
	ilist_initialize(b);
	slist_initialize(instructionNames);
	instructions_init(instructions);
}

int	main(int argc, char **argv)
{
	t_ilist				a;
	t_ilist				b;
	t_slist				instructionNames;
	t_instruction_infos	instructions[12];

	if (argc == 1)
		return (0);
	initialize(&a, &b, &instructionNames, instructions);
	if (!get_numbers(argv, &a))
	{
		ilist_destroy(&a);
		errorExit();
	}
	if (!get_instructions(&instructionNames, instructions))
	{
		destroy_lists(&a, &b, &instructionNames);
		errorExit();
	}
	execute(&instructionNames, instructions, &a, &b);
	printResult(&a, &b);
	printf("debug : list after execute : "); ilist_show(a, false);
	destroy_lists(&a, &b, &instructionNames);
	return (0);
}
