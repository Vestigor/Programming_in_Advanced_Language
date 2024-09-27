/*2353814 信05 马小龙*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入[0,100亿)之间的数字:" << endl;
	double n;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
	cin >> n;
	a1 = int(n / 10) / 100000000;
	a2 = int(n / 10) % 100000000 / 10000000;
	a3 = int(n / 10) % 10000000 / 1000000;
	a4 = int(n / 10) % 1000000 / 100000;
	a5 = int(n / 10) % 100000 / 10000;
	a6 = int(n / 10) % 10000 / 1000;
	a7 = int(n / 10) % 1000 / 100;
	a8 = int(n / 10) % 100 / 10;
	a9 = int(n / 10) % 10;
	a10 = int(floor((n / 10 - floor(n / 10)) * 10));
	a11 = int(round((n - floor(n)) * 100)) / 10;
	a12 = int(round((n - floor(n)) * 100)) % 10;
	cout << "十亿位" << " " << ":" << " " << a1 << endl;
	cout << "亿位  " << " " << ":" << " " << a2 << endl;
	cout << "千万位" << " " << ":" << " " << a3 << endl;
	cout << "百万位" << " " << ":" << " " << a4 << endl;
	cout << "十万位" << " " << ":" << " " << a5 << endl;
	cout << "万位  " << " " << ":" << " " << a6 << endl;
	cout << "千位  " << " " << ":" << " " << a7 << endl;
	cout << "百位  " << " " << ":" << " " << a8 << endl;
	cout << "十位  " << " " << ":" << " " << a9 << endl;
	cout << "圆    " << " " << ":" << " " << a10 << endl;
	cout << "角    " << " " << ":" << " " << a11 << endl;
	cout << "分    " << " " << ":" << " " << a12 << endl;
	
	return 0;
}