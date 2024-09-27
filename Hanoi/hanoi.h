/* 信05 2353814 马小龙 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

void initialize();
char menu();
void input(char* src, char* dst, char* tmp, int* n, char order);
void landscape();
void portrait(char order);
void speed();
void column();
void disc(char src, int n);
void display(char src, char dst);
void step(int src, int dst);
void shouhang(char src, char dst, int n, char order);
void detail(int n, char src, char tmp, char dst, char order);
void hanoi(int n, char src, char tmp, char dst, char order);
void game(int n, char src, char tmp, char dst, char order);