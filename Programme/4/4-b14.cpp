/*2353814 马小龙 信05*/
#include <iostream>
#include <cmath>
using namespace std;

void sit1()
{
	cout << "不是一元二次方程" << endl;
}

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

void sit3(double a, double b)
{
	double x;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}

void sit4(double a, double b, double delta)
{
	double m, n;
	m= -b / (2 * a);
	n = sqrt(-delta) / (2 * a);
	if (fabs(m) < 1e-6)
		m = 0;
	if (fabs(n) < 1e-6)
		n = 0;
	n = fabs(n);
	cout << "有两个虚根：" << endl;
	if (fabs(n - 1) < 1e-6) {
		if (m == 0) {
			cout << "x1=i"<<endl;
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

int main() 
{
	double a, b, c,delta;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	if (a == 0)
		sit1();
	else if (delta > 0)
		sit2(a, b, delta);
	else if (delta == 0)
		sit3(a, b);
	else
		sit4(a, b, delta);

	return 0;
}