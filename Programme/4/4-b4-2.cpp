/* 2353814 马小龙 信05 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	/*当由两个或多个字母坐标相同时*/
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu() {
	int a;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止，按左箭头不向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，按左箭头不向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6] ";

	while (1)
	{
		a = _getch();
		if (a <= '6' && a >= '0')
			break;
	}
	return a;
}

void move_by_ijkl(int huirao,int zhengque) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	init_border(hout);
	int x = 35, y = 9, a, b;
	gotoxy(hout, x, y);
	while (1) {
		a = _getch();
		if (zhengque == 1)
			if (a == 224)
				b=_getch();
		if (huirao == 0) {
			if ((a == 'i' || a == 'I') && y > 1) {
				y--;
				gotoxy(hout, x, y);
			}
			if ((a == 'k' || a == 'K') && y < 17) {
				y++;
				gotoxy(hout, x, y);
			}
			if ((a == 'j' || a == 'J') && x > 1) {
				x--;
				gotoxy(hout, x, y);
			}
			if ((a == 'l' || a == 'L') && x < 69) {
				x++;
				gotoxy(hout, x, y);
			}
		}
		else{
			if (a == 'i' || a == 'I') {
				y--;
				if (y == 0)
					y = 17;
				gotoxy(hout, x, y);
			}
			if (a == 'k' || a == 'K') {
				y++;
				if (y == 18)
					y = 1;
				gotoxy(hout, x, y);
			}
			if (a == 'j' || a == 'J') {
				x--;
				if (x == 0)
					x = 69;
				gotoxy(hout, x, y);
			}
			if (a == 'l' || a == 'L') {
				x++;
				if (x == 70)
					x = 1;
				gotoxy(hout, x, y);
			}
		}
		if (a == ' ') {
			cout << " " << "\b"<<" ";
			gotoxy(hout, x, y);
		}
		if (a == 'q' || a == 'Q') {
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (1) {
				a = _getch();
				if (a == 13) {
					cls(hout);
					return;
				}
			}
		}
	}
}

void move_by_arrow(int huirao) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	init_border(hout);
	int x = 35, y = 9, a;
	gotoxy(hout, x, y);
	while (1) {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (huirao == 0) {
				if ((a == 72) && y > 1) {
					y--;
					gotoxy(hout, x, y);
				}
				if ((a == 80) && y < 17) {
					y++;
					gotoxy(hout, x, y);
				}
				if ((a == 75) && x > 1) {
					x--;
					gotoxy(hout, x, y);
				}
				if ((a == 77) && x < 69) {
					x++;
					gotoxy(hout, x, y);
				}
			}
			else {
				if (a == 72) {
					y--;
					if (y == 0)
						y = 17;
					gotoxy(hout, x, y);
				}
				if (a == 80) {
					y++;
					if (y == 18)
						y = 1;
					gotoxy(hout, x, y);
				}
				if (a == 75) {
					x--;
					if (x == 0)
						x = 69;
					gotoxy(hout, x, y);
				}
				if (a == 77) {
					x++;
					if (x == 70)
						x = 1;
					gotoxy(hout, x, y);
				}
			}
		}
		if (a == ' ') {
			cout << " " << "\b" << " ";
			gotoxy(hout, x, y);
		}
		if (a == 'q' || a == 'Q') {
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (1) {
				a = _getch();
				if (a == 13) {
					cls(hout);
					return;
				}
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	cout << " ";
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	//srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	/* 显示初始的边框及其中的随机字符 */
	//init_border(hout);

	//暂停
	//getchar();

	//gotoxy(hout, 0, 23);
	//cout << "游戏结束，按回车键退出." << endl;

	//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
	//getchar();
	int a;
	while (1) {
		a = menu();
		switch (a) {
			case '0':
				cout << "0";
				return 0;
				break;
			case '1':
				move_by_ijkl(0, 0);
				break;
			case '2':
				move_by_ijkl(1, 0);
				break;
			case '3':
				move_by_arrow(0);
				break;
			case '4':
				move_by_arrow(1);
				break;
			case '5':
				move_by_ijkl(0, 1);
				break;
			case '6':
				move_by_ijkl(1, 1);
				break;
			default:
				break;
		}
	}

	return 0;
}

/******************************************************************
思考题解答：
1.可以重现此问题。解释：_getch()输入方向键后会返回两个值，其中左箭
头对应114和75，而75恰好为K的ASCII码；当输入左箭头后，224和75进入缓
冲区，随后将224赋值给变量a，此时a不满足任何一个分支条件，本次循环结
束，进入第二个循环，遇到a=_getch(),直接将缓冲区的75赋值给a，此时a满
足a==K，所以光标向下移动。
2.不一定会生成20个字母。有可能，当两个或多个字母坐标相同时，生成字母
的个数会小于20。
******************************************************************/