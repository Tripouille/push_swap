#include "list.h"
#include <stdio.h>

int main(void)
{
    t_list a;
    list_initialize(&a);
    list_show(a, false);

    list_push(&a, 1);
    list_push(&a, 2);
    list_push(&a, 3);
    list_push(&a, 4);
    list_push(&a, 5);
    list_push(&a, 6);
    list_push(&a, 7);

    while (list_size(&a) > 0)
    {
        printf("list size = %lu\n", list_size(&a));
        list_show(a, false);
        list_swap(&a);
        list_show(a, false);
        list_shift(&a);
    }
    list_destroy(&a);
    return (0);
}
