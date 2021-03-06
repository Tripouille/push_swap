#include "list.h"
#include <stdio.h>

int main(void)
{
    t_list a;
    list_initialize(&a);
    list_show(a, false);

    list_push(&a, 1);
    list_push(&a, 0);
   
    printf("is sort = %i\n", list_is_sort(&a, true));

    /*while (list_size(&a) > 0)
    {
        printf("list size = %lu\n", list_size(&a));
        list_show(a, false);
        list_swap(&a);
        list_show(a, false);
        list_shift(&a);
    }*/
    list_destroy(&a);
    return (0);
}
