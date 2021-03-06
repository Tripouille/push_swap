#include "instructions.h"

void    print_and_call(t_instruction_infos const instructions[], char *name,
							t_ilist *a, t_ilist *b)
{
    printf("%s\n", name);
    instructions_call(instructions, name, a, b);
}


void	sort(t_instruction_infos instructions[], t_ilist *a, t_ilist *b)
{
    int         smallest;

	while (!ilist_is_empty(a))
	{
        smallest = ilist_get_smallest(a);
        while (a->head->i != smallest)
            print_and_call(instructions, "rra", a, b);
        print_and_call(instructions, "pb", a, b);
	}
	while (!ilist_is_empty(b))
        print_and_call(instructions, "pa", a, b);
}

void	initialize(t_instruction_infos instructions[], t_ilist *a, t_ilist *b)
{
    instructions_init(instructions);
	ilist_initialize(a);
	ilist_initialize(b);
}

int		main(int ac, char **av)
{
    t_instruction_infos     instructions[12];
    t_ilist					a; 
    t_ilist					b;

	if (ac == 1)
		return (0);
	initialize(instructions, &a, &b);
	if (!get_numbers(av, &a))
	{
		ilist_destroy(&a);
		errorExit();
	}
    if (!ilist_is_sort(&a, false))
	    sort(instructions, &a, &b);
	//ilist_show(a, false);
	instructions_destroy_ab(&a, &b);
    return (0);
}
