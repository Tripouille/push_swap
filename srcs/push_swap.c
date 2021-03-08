#include "algorithms.h"

void	stock_and_call(t_slist *instructionNames, t_instruction_infos const instructions[],
						char const *name, t_stacks *stacks)
{
	slist_push(instructionNames, name);
	instructions_call(instructions, name, stacks);
}

static void	initialize(t_instruction_infos instructions[], t_slist *instructionNames, t_stacks *stacks)
{
	instructions_init(instructions);
	stacks_init(stacks);
	slist_initialize(instructionNames);
}

int		main(int ac, char **av)
{
	t_instruction_infos	 instructions[12];
	t_stacks				stacks;
	t_slist					instructionNames;

	if (ac == 1)
		return (0);
	initialize(instructions, &instructionNames, &stacks);
	if (!get_numbers(av, &stacks.a))
	{
		stacks_destroy(&stacks);
		errorExit();
	}
	if (!ilist_is_sort(&stacks.a, false))
		instructionNames = franky_sort(instructions, &stacks);
	slist_show(instructionNames, false);
	//ilist_show(a, false);
	if (!ilist_is_sort(&stacks.a, false))
		write(2, "NOT SORTED\n", 11);
	stacks_destroy(&stacks);
	slist_destroy(&instructionNames);
	return (0);
}
