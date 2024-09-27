/*2353814 ะล05 ยํะกม๚*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j, n;
	for (i = 1; i < 10; i++) {
		for (j = 1; j <= i;j++) {
			n = i * j;
			printf("%dx%d=%-4d", j, i, n);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}