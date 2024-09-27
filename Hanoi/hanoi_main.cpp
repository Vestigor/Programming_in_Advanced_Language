/* 信05 2353814 马小龙 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include "hanoi.h"
#include "cmd_console_tools.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	char order,key_return;
	char src, dst, tmp;
	int n;

	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		initialize();
		cct_cls();
		order = menu();
		if (order == '0')
			break;
		else if (order != '5')
			input(&src, &dst, &tmp, &n, order);
		if (order >= '4' && order <= '8') {
			cct_cls();
			cct_setcursor(CURSOR_INVISIBLE);
			if (order != '5')
				shouhang(src, dst, n, order);
			if (order == '4'|| order == '8')
				portrait(order);
		}
		if (order == '4') {
			cct_gotoxy(0, 17);
			cout << "初始: ";
			landscape();
		}
		else if (order == '5')
			column();
		else if (order == '6' || order == '7') {
			column();
			disc(src, n);
			if (order == '7') {
				Sleep(1000);
				if (n % 2 == 0)
					dst = tmp;
				step(src, dst);
				display(src, dst);
			}
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
		}
		else if(order == '8') {
			cct_gotoxy(0, 32);
			cout << "初始: ";
			landscape();
			column();
			disc(src, n);
			Sleep(1000);
		}
		if (order >= '1' && order <= '8'&& order!='5')
			hanoi(n, src, tmp, dst, order);
		cout << endl;
		if (order == '9')
			game(n, src, tmp, dst, order);
		if (order >= '4' && order <= '9')
			cct_gotoxy(0, 38);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		cout << "按回车键继续";
		while (1) {
			key_return = _getch();
			if (key_return == 13)
				break;
		}
	}
	cout << endl;
	
	return 0;
}
