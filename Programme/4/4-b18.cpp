/* 2353814 马小龙 信05 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int my_max(int a, int b)
{
	return a > b ? a : b;
}

int my_max(int a, int b, int c)
{
	return my_max(my_max(a, b), c);
}

int my_max(int a, int b, int c, int d)
{
	return my_max(my_max(a, b, c), d);
}

int main() 
{
	int num, a, b, c, d, max;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (num < 2 || num>4) {
			cout << "个数输入错误" << endl;
			break;
		}
		if (num == 2) {
			cin >> a >> b;
			if (cin.fail() || a <= 0 || b <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			max = my_max(a, b);
			cout << "max=" << max << endl;
			break;
		}
		else if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail() || a <= 0 || b <= 0 || c<=0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			max = my_max(a, b, c);
			cout << "max=" << max << endl;
			break;
		}
		else if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0 || d<=0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			max = my_max(a, b, c, d);
			cout << "max=" << max << endl;
			break;
		}
	}
	
	return 0;
}