#ifndef __ISTACK_H_
#define __ISTACK_H_

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int *data;
    int size;
    int top;
} istack;

/* initialize istack structure */

int istack_init(istack *st);

/* return amount of elements on the stack */

int istack_length(istack *st);

/* return value on top of the stack without removing it */

int istack_top(istack *st, int *out);

/* add new value on top of the stack */

int istack_push(istack *st, int value);

/* remove and return value from top of the stack */

int istack_pop(istack *st, int *out);

/* cleanup */

void istack_destroy(istack *st);

#ifdef __cplusplus
}
#endif

#endif /* _ISTACK_H_ */