#include <stdio.h>

#include "istack.h"

#define INIT_LENGTH 8

void istack_init(istack *st) {
    st->data = calloc(INIT_LENGTH, INIT_LENGTH * sizeof(int));
    if (st->data == NULL) {
        perror("Error: calloc failed");
        abort();
    }
    st->size = INIT_LENGTH;
    st->top = -1;
}

int istack_length(istack *st) { return st->top + 1; }

int istack_top(istack *st) {
    if (st->top < 0) {
        perror("Error: istack empty\n");
        abort();
    }
    return (int)st->data[st->top];
}

void istack_push(istack *st, int value) {
    if (st->top + 1 >= st->size) {
        void *n = realloc(st->data, 2 * st->size * sizeof(int));
        if (!n) {
            perror("Error: realloc failed\n");
            abort();
        }
        st->data = n;
        memset(&st->data[st->top + 1], 0, st->size * sizeof(int));
        st->size = st->size * 2;
    }
    st->top++;
    st->data[st->top] = value;
}

int istack_pop(istack *st) {
    int val;

    val = st->data[st->top];
    memset(&st->data[st->top], 0, sizeof(int));
    st->top--;
    return val;
}

void istack_destroy(istack *st) {
    free(st->data);
    st->data = NULL;
    st->size = 0;
    st->top = -1;
}
