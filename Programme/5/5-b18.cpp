/* 信05 2353814 马小龙 */
#include <iostream>
using namespace std;

int judge_password(int arg[])
{
	char n;
	int kuan = arg[0], daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0, i;
	for (i = 0; i < kuan;i++) {
		n = getchar();
		if (n == '\n')
			break;
		if (n >= 'A' && n <= 'Z') {
			daxie++;
		}
		else if (n >= 'a' && n <= 'z') {
			xiaoxie++;
		}
		else if (n >= '0' && n <= '9') {
			shuzi++;
		}
		else if ((n == '!' || (n >= '#' && n <= '&') || (n >= '*' && n <= '.') || n == '=' || n == '?' || n == '@' || n == 94 || n == '_')) {
			qita++;
		}
		if (i == kuan - 1) {
			while (1) {
				char mo=getchar();
				if (mo == '\n')
					break;
				else if (mo != ' ')
					return 0;
			}
		}
	}
	if (daxie + xiaoxie + shuzi + qita != kuan)
		return 0;
	else if (daxie < arg[1])
		return 0;
	else if (xiaoxie < arg[2])
		return 0;
	else if (shuzi < arg[3])
		return 0;
	else if (qita < arg[4])
		return 0;
	else
		return 1;
	
}

int judge_arg(int arg[])
{
	if (arg[0] < 12 || arg[0]>16)
		return 0;
	else if (arg[1] < 2 || arg[1]>arg[0])
		return 0;
	else if (arg[2] < 2 || arg[2]>arg[0])
		return 0;
	else if (arg[3] < 2 || arg[3]>arg[0])
		return 0;
	else if (arg[4] < 2 || arg[4]>arg[0])
		return 0;
	else if (arg[1] + arg[2] + arg[3] + arg[4] > arg[0])
		return 0;
	else
		return 1;
}

int main()
{
	char shouhang[1024], password[10][16] = { 0 }, ret;
	int arg[5], fanhui;
	for (int i = 0; i < 1024; i++) {
		ret = getchar();
		if (ret == '\n')
			break;
		shouhang[i] = ret;
	}
	for (int i = 0; i < 5; i++) {
		cin >> arg[i];
		if (cin.fail() != 0) {
			cout << "错误" << endl;
			return 0;
		}
	}
	getchar();
	fanhui = judge_arg(arg);
	if (fanhui == 0) {
		cout << "错误" << endl;
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		fanhui = judge_password(arg);
		if (fanhui == 0) {
			cout << "错误" << endl;
			return 0;
		}
	}
	cout << "正确" << endl;

	return 0;
}