/* 2353814 马小龙 信05 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int shu[9][9] = { 0 }, i, j, k;
	int math[9] = { 0 }, m, n, p, q;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			while (1) {
				cin >> shu[i][j];
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				if (shu[i][j] < 1 || shu[i][j]>9) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				break;
			}
		}
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = j + 1; k < 9; k++) {
				if (shu[i][j] == shu[i][k]) {
					//cout << "第" << i+1 << "行" << j+1 << "列和" << k+1 << "列相等，为" << shu[i][j]<<" "<< shu[i][k]<< endl;
					cout << "不是数独的解" << endl;
					return 0;
				}
			}
		}
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = j + 1; k < 9; k++) {
				if (shu[j][i] == shu[k][i]) {
					//cout << "第" << i+1 << "列" << j+1 << "行和" << k+1 << "行相等，为" << shu[j][i]<<" "<< shu[k][i]<< endl;
					cout << "不是数独的解" << endl;
					return 0;
				}
			}
		}
	}
	for (i = 0; i < 9; i = i + 3) {
		for (j = 0; j < 9; j = j + 3) {
			k = 0;
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					int a = i + m, b = j + n;
					math[k] = shu[a][b];
					k++;
				}
			}
			for (p = 0; p < 9; p++) {
				for (q = p + 1; q < 9; q++) {
					if (math[p] == math[q]) {
						//cout << "行为" << i + 1 << "-" << i + 3 << "，列为" << j + 1 << "-" << j + 3 << "的小九宫格有数字重复" << endl;
						cout << "不是数独的解" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "是数独的解" << endl;

	return 0;
}