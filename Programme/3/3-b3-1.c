/*2353814 信05 马小龙*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入[0,100亿)之间的数字:\n");
	double n;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
	scanf("%lf",&n);
	a1 = (int)(n / 10) / 100000000;
	a2 = (int)(n / 10) % 100000000 / 10000000;
	a3 = (int)(n / 10) % 10000000 / 1000000;
	a4 = (int)(n / 10) % 1000000 / 100000;
	a5 = (int)(n / 10) % 100000 / 10000;
	a6 = (int)(n / 10) % 10000 / 1000;
	a7 = (int)(n / 10) % 1000 / 100;
	a8 = (int)(n / 10) % 100 / 10;
	a9 = (int)(n / 10) % 10;
	a10 = (int)(floor((n / 10 - floor(n / 10)) * 10));
	a11 = (int)(round((n - floor(n)) * 100)) / 10;
	a12 = (int)(round((n - floor(n)) * 100)) % 10;
	printf("百亿位 : ");
	printf("%d\n", a1);
	printf("亿位   : ");
	printf("%d\n", a2);
	printf("千万位 : ");
	printf("%d\n", a3);
	printf("百万位 : ");
	printf("%d\n", a4);
	printf("十万位 : ");
	printf("%d\n", a5);
	printf("万位   : ");
	printf("%d\n", a6);
	printf("千位   : ");
	printf("%d\n", a7);
	printf("百位   : ");
	printf("%d\n", a8);
	printf("十位   : ");
	printf("%d\n", a9);
	printf("圆     : ");
	printf("%d\n", a10);
	printf("角     : ");
	printf("%d\n", a11);
	printf("分     : ");
	printf("%d\n", a12);

	return 0;
}