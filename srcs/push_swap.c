#include "algorithms.h"

void	stock_and_call(t_slist *instructionNames, t_instruction_infos const instructions[],
						char const *name, t_stacks *stacks)
{
	slist_push(instructionNames, name);
	instructions_call(instructions, name, &stacks->a, &stacks->b);
}

void	initialize(t_instruction_infos instructions[], t_stacks *stacks)
{
	instructions_init(instructions);
	ilist_initialize(&stacks->a);
	ilist_initialize(&stacks->b);
}

int		main(int ac, char **av)
{
	t_instruction_infos	 instructions[12];
	t_stacks				stacks;
	t_slist					instructionNames;

	if (ac == 1)
		return (0);
	initialize(instructions, &stacks);
	if (!get_numbers(av, &stacks.a))
	{
		ilist_destroy(&stacks.a);
		errorExit();
	}
	if (!ilist_is_sort(&stacks.a, false))
		instructionNames = franky_sort(instructions, &stacks);
	slist_show(instructionNames, false);
	//ilist_show(a, false);
	if (!ilist_is_sort(&stacks.a, false))
		write(2, "NOT SORTED\n", 11);
	instructions_destroy_ab(&stacks.a, &stacks.b);
	slist_destroy(&instructionNames);
	return (0);
}
