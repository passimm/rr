/* -*- Mode: C; tab-width: 8; c-basic-offset: 8; indent-tabs-mode: t; -*- */

#include "rrutil.h"

extern int cpuid_loop(int iterations);

int main(int argc, char** argv)
{
	int sum;
	getegid();
	sum = cpuid_loop(1000);
	atomic_printf("EXIT-SUCCESS; sum=%d\n", sum);
	return 0;
}
