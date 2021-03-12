#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

# include "utils.h"
# include "ilist.h"
# include "slist.h"
# include "instructions.h"
# include "stacks.h"
# include "options.h"

bool	get_instructions(t_slist *instructionNames,
			t_instruction_infos instructions[]);

#endif