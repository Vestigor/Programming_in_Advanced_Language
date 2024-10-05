/*2353814 马小龙 信05*/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

int zeller(int year, int month)
{
	int w, c, m, y;
	m = month;
	y = year;
	if (m == 1 || m == 2) {
		m = m + 12;
		y = y - 1;
	}
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + 1 - 1;
	while (w < 0)
		w = w + 7;
	w = w % 7;
	return w;
}

int main()
{
	int tian[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 }, day[3] = { 0 };
	int year, i, j, k, m, ret1, ret2;
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	if (leap(year))
		tian[1] = 29;
	else
		tian[1] = 28;
	cout << year << "年的日历:" << endl;
	cout << endl;
	for (m = 1; m <= 10; m = m + 3) {
		cout << setiosflags(ios::right) << setw(13) << m << "月" << setw(30) << m + 1 << "月" << setw(30) << m + 2 << "月" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
		day[0] = zeller(year, m);
		day[1] = zeller(year, m+1);
		day[2] = zeller(year, m+2);
		ret1 = 1;
		ret2 = 1;
		cout << resetiosflags(ios::right);
		for (i = 1; i <= 42; i++) {
			if (i <= day[0] || i > day[0] + tian[m - 1])
				cout << setiosflags(ios::left) << setw(4) << " ";
			else
				cout << setiosflags(ios::left) << setw(4) << i - day[0];
			if (i % 7 == 0) {
				cout << setiosflags(ios::left) << setw(4) << " ";
				for (j = ret1; j <= 42; j++) {
					if (j <= day[1]|| j>day[1] + tian[m])
						cout << setiosflags(ios::left) << setw(4) << " ";
					else
						cout << setiosflags(ios::left) << setw(4) << j - day[1];
					ret1 = j+1;
					if (j % 7 == 0) {
						cout << setiosflags(ios::left) << setw(4) << " ";
						for (k = ret2; k <= 42; k++) {
							if (k <= day[2]|| k>day[2] + tian[m + 1])
								cout << setiosflags(ios::left) << setw(4) << " ";
							else
								cout << setiosflags(ios::left) << setw(4) << k - day[2];
							ret2 = k+1;
							if (k % 7 == 0) {
								cout << endl;
								break;
							}
						}
						break;
					}
				}
			}
			if (i >= day[0] + tian[m - 1] && j >= day[1] + tian[m] && k >= day[2] + tian[m + 1]&& i==ret1-1 && i==ret2-1)
				break;
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}