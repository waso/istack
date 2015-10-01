#include <stdio.h>

#include "istack.h"

enum { INIT_LENGTH = 8 };

int istack_init(istack *st) {
    st->data = calloc(INIT_LENGTH, INIT_LENGTH * sizeof(int));
    if (st->data == NULL) {
        perror("Error: calloc failed");
        return -1;
    }
    st->size = INIT_LENGTH;
    st->top = -1;
    return 1;
}

int istack_length(istack *st) { return st->top + 1; }

int istack_top(istack *st, int *out) {
    if (st->top < 0) {
        perror("Error: istack empty\n");
        return -1;
    }
    *out = (int)st->data[st->top];
    return 1;
}

int istack_push(istack *st, int value) {
    if (st->top + 1 >= st->size) {
        void *n = realloc(st->data, 2 * st->size * sizeof(int));
        if (!n) {
            perror("Error: realloc failed\n");
            return -1;
        }
        st->data = n;
        memset(&st->data[st->top + 1], 0, st->size * sizeof(int));
        st->size = st->size * 2;
    }
    st->top++;
    st->data[st->top] = value;
    return 1;
}

int istack_pop(istack *st, int *out) {
    int val;
    if(st->top < 0) {
        perror("Error: stack empty");
        return -1;
    }
    val = st->data[st->top];
    memset(&st->data[st->top], 0, sizeof(int));
    st->top--;
    *out = val;
    return 1;
}

void istack_destroy(istack *st) {
    free(st->data);
    st->data = NULL;
    st->size = 0;
    st->top = -1;
}
