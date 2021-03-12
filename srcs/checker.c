#include "checker.h"

void	execute(t_slist *required_instructions,
	t_instruction_infos instructions[], t_stacks *stacks)
{
	t_slist_element	*i;

	i = required_instructions->head;
	while (i != required_instructions->tail)
	{
		instructions_call(instructions, i->s, stacks);
		i = i->next;
	}
	if (required_instructions->tail != NULL)
		instructions_call(instructions, required_instructions->tail->s,
			stacks);
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

static void	initialize(t_stacks *stacks, t_slist *required_instructions,
						t_instruction_infos instructions[])
{
	stacks_init(stacks);
	slist_initialize(required_instructions);
	instructions_init(instructions);
}

int	main(int argc, char **argv)
{
	t_stacks			stacks;
	t_slist				required_instructions;
	t_instruction_infos	instructions[12];

	if (argc == 1)
		return (0);
	initialize(&stacks, &required_instructions, instructions);
	if (!get_numbers(argv + 1, &stacks.a))
	{
		stacks_destroy(&stacks);
		errorExit();
	}
	if (!get_instructions(&required_instructions, instructions))
	{
		destroy_lists(&stacks, &required_instructions);
		errorExit();
	}
	execute(&required_instructions, instructions, &stacks);
	printResult(&stacks);
	destroy_lists(&stacks, &required_instructions);
	return (0);
}
