istack
====

Lightweight stack data structure specialized for intigers and implemented in plain C.


Usage
-----

	istack st;
	istack_init(&st);
	istack_push(&st, 123);
	printf("%d ", istack_top(&st));
	istack_destroy(&st);


License
-------

This software is distributed under MIT license.