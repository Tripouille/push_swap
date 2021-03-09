#include "benchmark.h"

static void	initialize(t_instruction_infos instructions[], t_stacks *stacks)
{
	instructions_init(instructions);
	stacks_init(stacks);
}

int		main(int ac, char **av)
{
	t_instruction_infos	 instructions[12];
	t_stacks				stacks;
	t_ilist					list;

	ilist_is_empty(&list);
	printf("actual size = %lu\n", list.size);
	ilist_push(&list, 10);
	ilist_unshift(&list, 10);
	printf("actual size = %lu\n", list.size);
	ilist_pop(&list); 
	printf("actual size = %lu\n", list.size);
	ilist_shift(&list); 
	printf("actual size = %lu\n", list.size);

	return(0);


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
