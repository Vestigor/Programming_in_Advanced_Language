/*2353814 信05 马小龙*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入半径和高度\n");
	const double pi = 3.14159;
	double r, h, a, b, c, d, e;
	scanf("%lf %lf", &r, &h);
	a = 2 * pi * r;
	b = pi * r * r;
	c = 4 * pi * r * r;
	d = pi * r * r * r * 4 / 3;
	e = pi * r * r * h;
	printf("圆周长    ");
	printf(" ");
	printf(":");
	printf(" ");
	printf("%.2lf\n", a);
	printf("圆面积    ");
	printf(" ");
	printf(":");
	printf(" ");
	printf("%.2lf\n", b);
	printf("圆球表面积");
	printf(" ");
	printf(":");
	printf(" ");
	printf("%.2lf\n", c);
	printf("圆球体积  ");
	printf(" ");
	printf(":");
	printf(" ");
	printf("%.2lf\n", d);
	printf("圆柱体积  ");
	printf(" ");
	printf(":");
	printf(" ");
	printf("%.2lf\n", e);
	
	return 0;
}