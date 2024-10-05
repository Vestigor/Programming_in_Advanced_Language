/* 信05 2353814 马小龙 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int zeller(int y, int m, int d) {
	int w, c;
	if (m == 1 || m == 2) {
		m = m + 12;
		y = y - 1;
	}
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	while (w < 0)
		w = w + 7;
	w = w % 7;
	return w;
}
int main()
{
	int year, month, day, week;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month > 12) {
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 1 || day>31) {
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 1 || day>30) {
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		else {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (day < 0 || day>29) {
					cout << "日不正确，请重新输入" << endl;
					continue;
				}
			}
			else {
				if (day < 0 || day>28) {
					cout << "日不正确，请重新输入" << endl;
					continue;
				}
			}
		}
		break;
	}
	week = zeller(year, month, day);
	if (week == 1)
		cout << "星期一" << endl;
	else if (week == 2)
		cout << "星期二" << endl;
	else if (week == 3)
		cout << "星期三" << endl;
	else if (week == 4)
		cout << "星期四" << endl;
	else if (week == 5)
		cout << "星期五" << endl;
	else if (week == 6)
		cout << "星期六" << endl;
	else
		cout << "星期日" << endl;

	return 0;
}