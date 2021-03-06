/* -*- Mode: C; tab-width: 8; c-basic-offset: 8; indent-tabs-mode: t; -*- */

#include "rrutil.h"

static void breakpoint2(void) {
	int break_here = 1;
	(void)break_here;
}

static void breakpoint3(void) {
	int break_here = 1;
	(void)break_here;
}

int main(int argc, char *argv[]) {
	/* NO SYSCALLS BETWEEN HERE AND RDTSC: next event for
	 * replay must be rdtsc */
	rdtsc();
	breakpoint2();
	atomic_printf("Write syscall...\n");
	breakpoint3();

	atomic_puts("EXIT-SUCCESS");
	return 0;
}
