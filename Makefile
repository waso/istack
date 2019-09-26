CC=gcc
CFLAGS=-Wall -Werror -O3 -pedantic -std=c11

all: libistack.a test

libistack.a: istack.o
	$(AR) rc $@ $^

%.o: %.c istack.h
	$(CC) -c $(CFLAGS) $< -o $@

test: istack_test
	./istack_test

istack_test:
	$(CC) istack.c istack.h istack_test.c -o $@

example: example.o libistack.a
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -f *.o
	rm -f istack_test
	rm -f libistack.a
	rm -f example

.PHONY: all clean test
