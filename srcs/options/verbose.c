#include "options.h"

static void	erase(void)
{
	ft_putstr_fd(2, " \r\33[2K\033[A\33[2K\033[A\33[2K");
}

static void	print_stacks(t_stacks const *stacks)
{
	ft_putstr_fd(2, "\033[36ma : ");
	ilist_show(&stacks->a, ' ');
	ft_putstr_fd(2, "\033[34mb : ");
	ilist_show(&stacks->b, ' ');
	ft_putstr_fd(2, "\033[0m");
}

static void	show_instructions_film(t_slist const *required_instructions,
	t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist_element	*element;

	element = required_instructions->head;
	print_stacks(stacks);
	while (element != required_instructions->tail)
	{
		usleep(1000000);
		erase();
		ft_putstr_fd(2, element->s);
		ft_putstr_fd(2, "\n");
		instructions_call(instructions, element->s, stacks);
		print_stacks(stacks);
		element = element->next;
	}
	usleep(1000000);
	erase();
	ft_putstr_fd(2, element->s);
	ft_putstr_fd(2, "\n");
	instructions_call(instructions, element->s, stacks);
	print_stacks(stacks);
}

static void	show_instructions_static(t_slist const *required_instructions,
	t_instruction_infos const instructions[], t_stacks *stacks)
{
	t_slist_element	*element;

	element = required_instructions->head;
	print_stacks(stacks);
	while (element != required_instructions->tail)
	{
		ft_putstr_fd(2, element->s);
		ft_putstr_fd(2, "\n");
		instructions_call(instructions, element->s, stacks);
		print_stacks(stacks);
		element = element->next;
	}
	ft_putstr_fd(2, element->s);
	ft_putstr_fd(2, "\n");
	instructions_call(instructions, element->s, stacks);
	print_stacks(stacks);
}

void	show_instructions(t_slist const *required_instructions,
	t_instruction_infos const instructions[], t_stacks *stacks,
	t_option options[])
{
	if (get_option(options, 'f')->active)
		show_instructions_film(required_instructions, instructions, stacks);
	else if (get_option(options, 'v')->active)
		show_instructions_static(required_instructions, instructions, stacks);
	else
		slist_show(required_instructions, '\n');
}