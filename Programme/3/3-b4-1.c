/*2353814 信05 马小龙*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入三角形的两边及其夹角(角度)\n");
	const float pi = 3.14159f;
	int a, b, c;
	float s, d;
	scanf("%d %d %d", &a, &b, &c);
	d = c * pi / 180;
	s = 0.5f * a * b * (float)sin(d);
	printf("三角形的面积为 : ");
	printf("%.3f\n", s);

	return 0;
}