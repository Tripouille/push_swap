#include "algorithms.h"

void	stock_and_call(t_slist *instructionNames, t_instruction_infos const instructions[],
						char const *name, t_stacks *stacks)
{
	slist_push(instructionNames, name);
	instructions_call(instructions, name, stacks);
}
