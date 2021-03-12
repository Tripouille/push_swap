#include "benchmark.h"
#include "options.h"

static int	help(t_option options[])
{
	int		i;

	i = -1;
	printf("push_swap help:\n");
	while (options[++i].name)
		printf("-%c: %s\n", options[i].name, options[i].description);
	return (0);
}

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

	(void)ac;
	options_initialize_push_swap(options);
	options_parse(options, &av);
	if (get_option(options, 'h')->active)
		return (help(options));
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
