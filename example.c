#include <stdio.h>

#include "istack.h"

int main(int argc, char *argv[])
{
    istack st;
    int i;

    istack_init(&st);
    for (i = 0; i < 32; i++) {
        istack_push(&st, i);
        printf("%d ", istack_top(&st));
    }
    istack_destroy(&st);
    printf("\n");
    return 0;
}