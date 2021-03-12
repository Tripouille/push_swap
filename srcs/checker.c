#include "checker.h"

void	execute(t_slist *instructionNames, t_instruction_infos instructions[],
				t_stacks *stacks)
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

static void	initialize(t_stacks *stacks, t_slist *instructionNames,
						t_instruction_infos instructions[])
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
	if (!get_numbers(argv + 1, &stacks.a))
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
	destroy_lists(&stacks, &instructionNames);
	return (0);
}
