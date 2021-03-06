#include "utils.h"

void    instructions_set(t_instruction_infos *instruction_infos, char *name,
						instruction function)
{
	ft_strcpy(instruction_infos->name, name);
	instruction_infos->funtion = function;
}

void    instructions_init(t_instruction_infos instructions[])
{
	instructions_set(instructions + 0, "sa", NULL);
	instructions_set(instructions + 1, "sb", NULL);
	instructions_set(instructions + 2, "ss", NULL);
	instructions_set(instructions + 3, "pa", NULL);
	instructions_set(instructions + 4, "pb", NULL);
	instructions_set(instructions + 5, "ra", NULL);
	instructions_set(instructions + 6, "rb", NULL);
	instructions_set(instructions + 7, "rr", NULL);
	instructions_set(instructions + 8, "rra", NULL);
	instructions_set(instructions + 9, "rrb", NULL);
	instructions_set(instructions + 10, "rrr", NULL);
	instructions_set(instructions + 11, "", NULL);
}

void    instructions_call(t_instruction_infos const instructions[], char *name,
							t_ilist *a, t_ilist *b)
{
	int		i;

	i = 0;
	while (instructions[i].name[0]
	&& ft_strcmp(instructions[i].name, name) == 0)
		i++;
	instructions[i].funtion(a, b);
}


bool    instructions_contain(t_instruction_infos const instructions[], char *name)
{
	int		i;

	i = 0;
	while (instructions[i].name[0]
	&& ft_strcmp(instructions[i].name, name) == 0)
		i++;
	return (instructions[i].name[0]);
}

