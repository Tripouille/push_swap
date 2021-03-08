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

void	execute(t_slist *instructionNames, t_instruction_infos instructions[], t_stacks *stacks)
{
	t_slist_element	*i;

	i = instructionNames->head;
	while (i != instructionNames->tail)
	{
		instructions_call(instructions, i->s, stacks);
		i = i->next;
	}
	if (instructionNames->tail != NULL)
		instructions_call(instructions, instructionNames->tail->s, stacks);
}

void	printResult(t_stacks *stacks)
{
	if (ilist_is_empty(&stacks->b) && ilist_is_sort(&stacks->a, false))
		printf("OK\n");
	else
		printf("KO\n");
}

void	destroy_lists(t_stacks *stacks, t_slist *instructions)
{
	stacks_destroy(stacks);
	slist_destroy(instructions);
}

static void	initialize(t_stacks *stacks, t_slist *instructionNames, t_instruction_infos instructions[])
{
	stacks_init(stacks);
	slist_initialize(instructionNames);
	instructions_init(instructions);
}

int	main(int argc, char **argv)
{
	t_stacks			stacks;
	t_slist				instructionNames;
	t_instruction_infos	instructions[12];

	if (argc == 1)
		return (0);
	initialize(&stacks, &instructionNames, instructions);
	if (!get_numbers(argv, &stacks.a))
	{
		stacks_destroy(&stacks);
		errorExit();
	}
	if (!get_instructions(&instructionNames, instructions))
	{
		destroy_lists(&stacks, &instructionNames);
		errorExit();
	}
	execute(&instructionNames, instructions, &stacks);
	printResult(&stacks);
	//printf("debug : list after execute : "); ilist_show(stacks.a, false);
	destroy_lists(&stacks, &instructionNames);
	return (0);
}
