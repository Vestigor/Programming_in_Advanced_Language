/* 信05 2353814 马小龙 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void calender(int year, int month)
{
	/* 按需添加代码 */
	int w, c, m, y, i, j, n;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		n = 31;
	else if (month == 2) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			n = 29;
		else
			n = 28;
	}
	else
		n = 30;
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
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	for (i = 1; i <= w; i++) {
		if (i == 1)
			cout << std::right << setw(4) << " ";
		else
			cout << std::right << setw(8) << " ";
	}
	for (j = 1; j <= n; j++) {
		if ((w + j - 1) % 7 == 0)
			cout << std::right << setw(4) << j;
		else
			cout << std::right << setw(8) << j;
		if ((w + j) % 7 == 0)
			cout << std::right << setw(4) << " " << endl;
		if ((w + j) % 7 != 0 && j == n)
			cout << std::right << setw(4) << " " << endl;
	}
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}
int main()
{
	int year, month, day = 1;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
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
		break;
	}
	calender(year, month);

	return 0;
}