#include "instructions.h"

void initialize(t_instruction_infos instructions[], t_ilist *a, t_ilist *b)
{
    instructions_init(instructions);
	ilist_initialize(a);
	ilist_initialize(b);
}

int main(int ac, char **av)
{
    t_instruction_infos     instructions[12];
    t_ilist					a; 
    t_ilist					b;

	if (ac == 1)
		return (1);
	initialize(instructions, &a, &b);
	get_numbers(av, &a);
	ilist_show(a, false);
	instructions_rotate_a(&a, &b);
	ilist_show(a, false);
	instructions_destroy_ab(&a, &b);
    return (0);
}
