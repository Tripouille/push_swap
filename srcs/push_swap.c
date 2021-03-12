#include "benchmark.h"
#include "options.h"

static void	initialize(t_instruction_infos instructions[], t_stacks *stacks)
{
	instructions_init(instructions);
	stacks_init(stacks);
}

int	main(int ac, char **av)
{
	t_instruction_infos	instructions[12];
	t_stacks			stacks;
	t_option			options[10];

	if (ac == 1)
		return (0);
	options_initialize_push_swap(options);
	//printf("avant %s", *av);
	options_parse(options, &av);
	//printf("apres %s", *av);
	initialize(instructions, &stacks);
	if (!get_numbers(av, &stacks.a))
	{
		stacks_destroy(&stacks);
		errorExit();
	}
	print_best_algo(instructions, &stacks, options);
	stacks_destroy(&stacks);
	return (0);
}
