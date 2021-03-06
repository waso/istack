#include <stdio.h>

#include "istack.h"

int main(int argc, char *argv[]) {
    istack st;
    int i;
    int stocks[] = {100, 80, 60, 70, 60, 75, 85};
    int spans[7];
    int val;
    int arr_size;

    spans[0] = 1;

    istack_init(&st);
    istack_push(&st, 0);

    arr_size = sizeof(stocks)/sizeof(int);
    for (i = 1; i < arr_size; i++) {
        istack_top(&st, &val);
        while (istack_length(&st) > 0 && stocks[val] <= stocks[i]) {
            istack_pop(&st, &val);
            istack_top(&st, &val);
        }

        istack_top(&st, &val);
        spans[i] = (istack_length(&st) == 0) ? (i + 1) : (i - val);
        istack_push(&st, i);
    }
    istack_destroy(&st);


    for (i = 0; i < arr_size; i++) {
        printf("%d ", spans[i]);
    }
    printf("\n");
    return 0;
}