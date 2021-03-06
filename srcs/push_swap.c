#include "ilist.h"
#include "utils.h"
#include <stdio.h>

int main(void)
{
    t_instruction_infos     instructions[12];

    instructions_init(instructions);
    int i = -1;
    while (instructions[++i].name[0])
        printf("%s\n", instructions[i].name);
    printf("contain = %i", instructions_contain(instructions, "prout"));
    return (0);
}
