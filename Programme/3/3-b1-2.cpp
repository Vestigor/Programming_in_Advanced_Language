#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入半径和高度" << endl;
	const double pi = 3.14159;
	double r,h,a,b,c,d,e;
	cin >> r >> h;
	a = 2 * pi * r;
	b = pi * r * r;
	c = 4 * pi * r * r;
	d = pi * r * r * r * 4 / 3;
	e = pi * r * r * h;
	cout << "圆周长    " << " " << ":" << " " << setprecision(2) << fixed << a << endl;
	cout << "圆面积    " << " " << ":" << " " << setprecision(2) << fixed << b << endl;
	cout << "圆球表面积" << " " << ":" << " " << setprecision(2) << fixed << c << endl;
	cout << "圆球体积  " << " " << ":" << " " << setprecision(2) << fixed << d << endl;
	cout << "圆柱体积  " << " " << ":" << " " << setprecision(2) << fixed << e << endl;

	return 0;
}