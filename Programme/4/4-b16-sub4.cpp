/*2353814 马小龙 信05*/
#include <iostream>
#include <cmath>
using namespace std;

void sit4(double a, double b, double delta)
{
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