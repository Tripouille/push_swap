#include "utils.h"

static void	erase(void)
{
	ft_putstr_fd(2, " \r\33[2K\033[A");
}

static void	print_stacks(t_stacks const *stacks)
{
	ft_putstr_fd(2, "\033[36ma : ");
	ilist_show(&stacks->a, ' ');
	ft_putstr_fd(2, "\033[34mb : ");
	ilist_show(&stacks->b, ' ');
	ft_putstr_fd(2, "\033[0m");
}

void	show_instructions_verbose(t_slist const *required_instructions,
	t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist_element	*element;

	element = required_instructions->head;
	print_stacks(stacks);
	while (element != required_instructions->tail)
	{
		usleep(1000000);
		ft_putstr_fd(2, element->s);
		instructions_call(instructions, element->s, stacks);
		erase();
		print_stacks(stacks);
		element = element->next;
	}
	ft_putstr_fd(2, element->s);
	ft_putstr_fd(2, "\n");
	print_stacks(stacks);
	print_stacks(stacks);
}