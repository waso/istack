#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int test_passed = 0;
static int test_failed = 0;

/* Terminate current test with error */
#define fail() return __LINE__

/* Successfull end of the test case */
#define done() return 0

/* Check single condition */
#define check(cond)                                                                                \
    do {                                                                                           \
        if (!(cond)) fail();                                                                       \
    } while (0)

/* Test runner */
static void test(int (*func)(void), const char *name) {
    int r = func();
    if (r == 0) {
        test_passed++;
    } else {
        test_failed++;
        printf("FAILED: %s (at line %d)\n", name, r);
    }
}

#include "istack.h"

int test_simple() {
    istack st;
    int i;

    istack_init(&st);
    check(istack_length(&st) == 0);
    for (i = 0; i < 10; i++) {
        istack_push(&st, i);
        check(istack_top(&st) == i);
    }
    check(istack_length(&st) == 10);
    for (i = 9; i >= 0; i--) {
        check(istack_pop(&st) == i);
        check(istack_length(&st) == i);
    }
    istack_destroy(&st);

    return 0;
}

int main() {
    test(test_simple, "simple test case");
    printf("\nPASSED: %d\nFAILED: %d\n", test_passed, test_failed);
    return 0;
}