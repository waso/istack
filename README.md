istack
====

Lightweight stack data structure specialized for intigers and implemented in plain C.


Usage
-----

	istack st;
	int val;

	istack_init(&st);
	istack_push(&st, 123);
	istack_top(&st, &val);

	printf("%d ", val);
	istack_destroy(&st);


License
-------

This software is distributed under MIT license.