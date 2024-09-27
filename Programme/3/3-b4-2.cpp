/*2353814 信05 马小龙*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	const float pi = 3.14159f;
	int a, b, c;
	float s,d;
	cin >> a >> b >> c;
	d = c * pi / 180;
	s = 1.0f / 2 * a * b * sin(d);
	cout << "三角形的面积为" << " " << ":" << " " << setprecision(3) << fixed << s << endl;

	return 0;
} 