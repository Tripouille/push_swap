#include "instructions.h"

void	instructions_set(t_instruction_infos *instruction_infos, char *name,
						instruction function)
{
	ft_strcpy(instruction_infos->name, name);
	instruction_infos->funtion = function;
}

void	instructions_init(t_instruction_infos instructions[])
{
	instructions_set(instructions + 0, "sa", instructions_swap_a);
	instructions_set(instructions + 1, "sb", instructions_swap_b);
	instructions_set(instructions + 2, "ss", instructions_swap_ab);
	instructions_set(instructions + 3, "pa", instructions_push_a);
	instructions_set(instructions + 4, "pb", instructions_push_b);
	instructions_set(instructions + 5, "ra", instructions_rotate_a);
	instructions_set(instructions + 6, "rb", instructions_rotate_b);
	instructions_set(instructions + 7, "rr", instructions_rotate_ab);
	instructions_set(instructions + 8, "rra", instructions_reverse_rotate_a);
	instructions_set(instructions + 9, "rrb", instructions_reverse_rotate_b);
	instructions_set(instructions + 10, "rrr", instructions_reverse_rotate_ab);
	instructions_set(instructions + 11, "", NULL);
}

void	instructions_call(t_instruction_infos const instructions[],
							char const *name, t_stacks *stacks)
{
	int		i;

	i = 0;
	while (instructions[i].name[0] && ft_strcmp(instructions[i].name, name))
		i++;
	instructions[i].funtion(stacks);
}

bool	instructions_contain(t_instruction_infos const instructions[],
								char *name)
{
	int		i;

	i = 0;
	while (instructions[i].name[0] && ft_strcmp(instructions[i].name, name))
		i++;
	return (instructions[i].name[0]);
}
