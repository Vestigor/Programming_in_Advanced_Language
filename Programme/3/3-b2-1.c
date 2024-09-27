/*2353814 信05 马小龙*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int n, a, b, c, d, e;
	scanf("%d",&n);
	a = n / 10000;
	b = n % 10000 / 1000;
	c = n % 1000 / 100;
	d = n % 100 / 10;
	e = n % 10;
	printf("万位 : ");
	printf("%d\n", a);
	printf("千位 : ");
	printf("%d\n", b);
	printf("百位 : ");
	printf("%d\n", c);
	printf("十位 : ");
	printf("%d\n", d);
	printf("个位 : ");
	printf("%d\n", e);

	return 0;
}