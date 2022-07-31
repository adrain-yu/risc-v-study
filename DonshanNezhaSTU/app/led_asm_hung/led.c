#include <stdio.h>

int main(int argc, char *argv[])
{
	asm volatile (
		"li t0, 0x2000060\n"
		"li t1, 0xffffff14\n"
		"sw t1, 0(t0)\n"
		"li t4, 2\n"
		"li t5, 0x2000070\n"
		"sw t4, 0(t5)\n"
	);

	return 0;
}
