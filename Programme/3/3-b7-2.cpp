/*2353814 信05 马小龙*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入找零值：" << endl;
	double n;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a, b;
	cin >> n;
	a1 = int(n) / 50;
	a2 = (int(n) - 50 * a1) / 20;
	a3 = (int(n) - 50 * a1 - 20 * a2) / 10;
	a4 = (int(n) - 50 * a1 - 20 * a2 - 10 * a3) / 5;
	a5 = int(n) - 50 * a1 - 20 * a2 - 10 * a3 - 5 * a4;
	b = int(round((n - floor(n)) * 100));
	a6 = b / 50;
	a7 = (b - 50 * a6) / 10;
	a8 = (b - 50 * a6 - 10 * a7) / 5;
	a9 = (b - 50 * a6 - 10 * a7 - 5 * a8) / 2;
	a10 = b - 50 * a6 - 10 * a7 - 5 * a8 - 2 * a9;
	a = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
	cout << "共" << a << "张找零，具体如下：" << endl;
	if (a1 > 0)
		cout << "50元" << " " << ":" << " " << a1 << "张" << endl;
	if (a2 > 0)
		cout << "20元" << " " << ":" << " " << a2 << "张" << endl;
	if (a3 > 0)
		cout << "10元" << " " << ":" << " " << a3 << "张" << endl;
	if (a4 > 0)
		cout << "5元 " << " " << ":" << " " << a4 << "张" << endl;
	if (a5 > 0)
		cout << "1元 " << " " << ":" << " " << a5 << "张" << endl;
	if (a6 > 0)
		cout << "5角 " << " " << ":" << " " << a6 << "张" << endl;
	if (a7 > 0)
		cout << "1角 " << " " << ":" << " " << a7 << "张" << endl;
	if (a8 > 0)
		cout << "5分 " << " " << ":" << " " << a8 << "张" << endl;
	if (a9 > 0)
		cout << "2分 " << " " << ":" << " " << a9 << "张" << endl;
	if (a10 > 0)
		cout << "1分 " << " " << ":" << " " << a10 << "张" << endl;

	return 0;
}