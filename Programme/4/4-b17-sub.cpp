/*2353814 马小龙 信05*/
#include <iostream>
#include <cmath>
using namespace std;

extern double a, b, c;

void sit1()
{
	cout << "不是一元二次方程" << endl;
}

void sit2()
{
	double delta;
	delta = b * b - 4 * a * c;
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

void sit3()
{
	double x;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}

void sit4()
{
	double delta;
	delta = b * b - 4 * a * c;
	double m, n;
	m = -b / (2 * a);
	n = sqrt(-delta) / (2 * a);
	if (fabs(m) < 1e-6)
		m = 0;
	if (fabs(n) < 1e-6)
		n = 0;
	n = fabs(n);
	cout << "有两个虚根：" << endl;
	if (fabs(n - 1) < 1e-6) {
		if (m == 0) {
			cout << "x1=i" << endl;
			cout << "x2=-i" << endl;
		}
		else {
			cout << "x1=" << m << "+i" << endl;
			cout << "x2=" << m << "-i" << endl;
		}

	}
	else {
		if (m == 0) {
			cout << "x1=" << n << "i" << endl;
			cout << "x2=-" << n << "i" << endl;
		}
		else {
			cout << "x1=" << m << "+" << n << "i" << endl;
			cout << "x2=" << m << "-" << n << "i" << endl;
		}
	}
}