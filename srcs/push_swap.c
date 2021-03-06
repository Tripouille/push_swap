#include "instructions.h"

void    print_and_call(t_instruction_infos const instructions[], char const *name,
							t_ilist *a, t_ilist *b)
{
	printf("%s\n", name);
	instructions_call(instructions, name, a, b);
}

void    putSmallestOnTop(t_instruction_infos instructions[], t_ilist *a)
{
	t_ilist_element         *smallest;
	int						ra_length;		
	int						rra_length;
	char const				*rotate;
	t_ilist_element         *element;

	smallest = ilist_get_smallest(a);

	element = a->head;
	ra_length = 0;
	while (element != smallest)
	{
		element = element->next;
		ra_length += 1;
	}
	rra_length = ilist_size(a) - ra_length;
	if (ra_length < rra_length)
		rotate = "ra";
	else
		rotate = "rra";
	while (a->head != smallest)
		print_and_call(instructions, rotate, a, NULL);
}

void	sort(t_instruction_infos instructions[], t_ilist *a, t_ilist *b)
{

	while (!ilist_is_empty(a))
	{
		if (a->head->i > a->head->next->i)
			print_and_call(instructions, "sa", a, b);
		putSmallestOnTop(instructions, a);
		if (ilist_is_sort(a, false))
			break ;
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
