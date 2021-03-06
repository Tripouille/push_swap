#include "ilist.h"
#include <stdio.h>

int main(void)
{
    t_ilist a;
    ilist_initialize(&a);
    ilist_show(a, false);

    ilist_push(&a, 1);
    ilist_push(&a, 0);
   
    printf("is sort = %i\n", ilist_is_sort(&a, true));

    /*while (list_size(&a) > 0)
    {
        printf("list size = %lu\n", list_size(&a));
        list_show(a, false);
        list_swap(&a);
        list_show(a, false);
        list_shift(&a);
    }*/
    ilist_destroy(&a);
    return (0);
}
