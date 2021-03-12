#include "options.h"

static void	sleep_erase(void)
{
	usleep(1000000);
	printf("\r\33[2K\033[A\33[2K\033[A\33[2K");
}

static void	print_stacks(t_stacks const *stacks)
{
	printf("\033[31ma : ");
	ilist_show(&stacks->a, ' ');
	printf("\033[33mb : ");
	ilist_show(&stacks->b, ' ');
	printf("\033[0m");
}

static void	show_instructions_film(t_slist const *required_instructions,
t_instruction_infos const instructions[], t_stacks *stacks, bool color_last)
{
	t_slist_element	*element;

	element = required_instructions->head;
	print_stacks(stacks);
	while (element != required_instructions->tail)
	{
		sleep_erase();
		printf("%s\n", element->s);
		instructions_call(instructions, element->s, stacks);
		print_stacks(stacks);
		element = element->next;
	}
	sleep_erase();
	if (color_last)
		printf("\033[32m%s\033[0m\n", element->s);
	else
		printf("\033[32m%s\033[0m\n", element->s);
	instructions_call(instructions, element->s, stacks);
	print_stacks(stacks);
}

static void	show_instructions_static(t_slist const *required_instructions,
t_instruction_infos const instructions[], t_stacks *stacks, bool color_last)
{
	t_slist_element	*element;

	element = required_instructions->head;
	print_stacks(stacks);
	while (element != required_instructions->tail)
	{
		printf("%s\n", element->s);
		instructions_call(instructions, element->s, stacks);
		print_stacks(stacks);
		element = element->next;
	}
	if (color_last)
		printf("\033[32m%s\033[0m\n", element->s);
	else
		printf("\033[32m%s\033[0m\n", element->s);
	instructions_call(instructions, element->s, stacks);
	print_stacks(stacks);
}

void	show_instructions(t_slist const *required_instructions,
	t_instruction_infos const instructions[], t_stacks *stacks,
	t_option options[])
{
	if (get_option(options, 'f')->active)
		show_instructions_film(required_instructions, instructions, stacks,
			get_option(options, 'c')->active);
	else if (get_option(options, 'v')->active)
		show_instructions_static(required_instructions, instructions, stacks,
			get_option(options, 'c')->active);
	else if (get_option(options, 'c')->active)
		slist_show_color(required_instructions, '\n');
	else
		slist_show(required_instructions, '\n');
}
