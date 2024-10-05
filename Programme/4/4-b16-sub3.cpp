/*2353814 马小龙 信05*/
#include <iostream>
#include <cmath>
using namespace std;

void sit3(double a, double b)
{
	double x;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}
