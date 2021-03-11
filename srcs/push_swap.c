#include "benchmark.h"

static void	initialize(t_instruction_infos instructions[], t_stacks *stacks)
{
	instructions_init(instructions);
	stacks_init(stacks);
}

int	main(int ac, char **av)
{
	t_instruction_infos	instructions[12];
	t_stacks			stacks;

	if (ac == 1)
		return (0);
	initialize(instructions, &stacks);
	if (!get_numbers(av, &stacks.a))
	{
		stacks_destroy(&stacks);
		errorExit();
	}
	print_best_algo(instructions, &stacks);
	stacks_destroy(&stacks);
	return (0);
}
