#include <stdio.h>

#include "istack.h"

int main(int argc, char *argv[])
{
    istack st;
    int i;
    int val;

    istack_init(&st);
    for (i = 0; i < 32; i++) {
        istack_push(&st, i);
        istack_top(&st, &val);
        printf("%d ", val);
    }
    istack_destroy(&st);
    printf("\n");
    return 0;
}