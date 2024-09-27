/* 2353814 马小龙 信05 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

void menu(char *porder)
{
	cout << setfill('-') << setw(60) << "-" << endl;
	cout << " 1.内部数组，生成初始状态，寻找是否有初始可消除项" << endl;
	cout << " 2.内部数组，消除初始可消除项后非0项下落并用0填充" << endl;
	cout << " 3.内部数组，消除初始可消除项后查找消除提示" << endl;
	cout << " 4.n*n的框架(无分隔线)，显示初始状态" << endl;
	cout << " 5.n*n的框架(有分隔线)，显示初始状态" << endl;
	cout << " 6.n*n的框架(无分隔线)，显示初始状态及初始可消除项" << endl;
	cout << " 7.n*n的框架(有分隔线)，消除初始可消除项后显示消除提示" << endl;
	cout << " 8.cmd图形界面完整版(有分隔线，鼠标移动时显示坐标，右键退出)" << endl;
	cout << " 9.cmd图形界面完整版" << endl;
	cout << setfill('-') << setw(60) << "-" << endl;
	cout << "[请选择:] ";
	while (1) {
		*porder = _getch();
		if (*porder < '0' || *porder > '9')
			continue;
		else {
			cout << *porder << endl;
			break;
		}
	}
	Sleep(100);
}