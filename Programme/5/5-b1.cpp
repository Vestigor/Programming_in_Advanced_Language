/* 2353814 马小龙 信05 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int a[21], i, j, k, ret;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20; i++) {
		cin >> a[i];
		if (a[i] <= 0) {
			i++;
			break;
		}
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	i--;
	if (a[0] <= 0) {
		cout << "无效输入" << endl;
		return 0;
	}
	if (a[i] <= 0)
		i--;
	//cout << "i=" << i << endl;
	cout << "原数组为：" << endl;
	for (j = 0; j <= i; j++)
		cout << a[j] << ' ';
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	i++;
	cin >> a[i];
	for (k = 0; k <= i; k++) {
		ret = a[i] < a[k];
		if (ret == 1) {
			int b = a[i],m;
			for (m = i; m > k; m--)
				a[m] = a[m - 1];
			a[k] = b;
			break;
		}
	}
	//cout << "i=" << i << endl;
	cout << "插入后的数组为：" << endl;
	for (j = 0; j <= i; j++)
		cout << a[j] << ' ';
	cout << endl;

	return 0;
}