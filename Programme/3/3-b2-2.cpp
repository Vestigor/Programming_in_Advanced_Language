/*2353814 信05 马小龙*/
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;
	int n, a, b, c, d, e;
	cin >> n;
	a = n / 10000;
	b = n % 10000 / 1000;
	c = n % 1000 / 100;
	d = n % 100 / 10;
	e = n % 10;
	cout << "万位" << " " << ":" << " " << a << endl;
	cout << "千位" << " " << ":" << " " << b << endl;
	cout << "百位" << " " << ":" << " " << c << endl;
	cout << "十位" << " " << ":" << " " << d << endl;
	cout << "个位" << " " << ":" << " " << e << endl;

	return 0;
}