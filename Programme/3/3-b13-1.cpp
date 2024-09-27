/* 信05 2353814 马小龙 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int y, m, d, n, i, j;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (y < 2000 || y > 2030) {
			cout << "输入非法，请重新输入" << endl;
			continue;
		}	
		if (m < 1 || m > 12) {
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		break;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		n = 31;
	else if (m == 2) {
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			n = 29;
		else
			n = 28;
	}
	else
		n = 30;
	while (1) {
		cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (d < 0 || d > 7) {
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		cout << endl;
		break;
	}
	cout << y << "年" << m << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	for (i = 1; i <= d; i++) {
		if (i == 1)
			cout << std::right<< setw(4)<<" ";
		else
			cout << std::right << setw(8)<<" ";
	}
	for (j = 1; j <= n; j++) {
		if ((d + j - 1) % 7 == 0)
			cout << std::right << setw(4) << j;
		else
			cout << std::right << setw(8) << j;
		if ((d + j) % 7 == 0)
			cout << std::right << setw(4) << " " << endl;
		if ((d + j) % 7 != 0 && j == n)
			cout << std::right << setw(4) << " ";
	}
	cout << endl;

	return 0;
}