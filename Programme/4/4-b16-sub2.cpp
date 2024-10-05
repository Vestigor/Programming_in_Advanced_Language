/*2353814 马小龙 信05*/
#include <iostream>
#include <cmath>
using namespace std;

void sit2(double a, double b, double delta)
{
	double x1, x2, max, min;
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	max = x1 > x2 ? x1 : x2;
	min = x1 < x2 ? x1 : x2;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << max << endl;
	cout << "x2=" << min << endl;
}