/* 信05 2353814 马小龙 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int topA = 0, topB = 0, topC = 0;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
int num = 1, velocity=0;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void initialize()
{
    topA = 0;
    topB = 0;
    topC = 0;
    num = 1;
    velocity = 0;
    for (int i = 0; i < 10; i++) {
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
    }
}
void speed()
{
    if (velocity == 0) {
        while (_getch() != 13)
            ;
    }
    else if (velocity == 1)
        Sleep(200);
    else if (velocity == 2)
        Sleep(150);
    else if (velocity == 3)
        Sleep(100);
    else if (velocity == 4)
        Sleep(50);
    else
        Sleep(0);
}

void column()
{
    cct_showch(1, 15, ' ', 14, 14, 23);
    cct_showch(33, 15, ' ', 14, 14, 23);
    cct_showch(65, 15, ' ', 14, 14, 23);
    for (int i = 1; i <= 12; i++) {
        cct_showch(12, 15-i, ' ', 14, 14, 1);
        Sleep(50);
        cct_showch(44, 15-i, ' ', 14, 14, 1);
        Sleep(50);
        cct_showch(76, 15-i, ' ', 14, 14, 1);
        Sleep(50);
    }
    cct_setcolor(0, 7);
}

void disc(char src,int n)
{
    if (src == 65) {
        for (int i = n; i > 0; i--) {
            cct_showch(12 - i, 14 + i - n, ' ', i, i, 2 * i + 1);
            Sleep(50);
        }
    }
    if (src == 66) {
        for (int i = n; i > 0; i--) {
            cct_showch(44 - i, 14 + i - n, ' ', i, i, 2 * i + 1);
            Sleep(50);
        }
    }
    if (src == 67) {
        for (int i = n; i > 0; i--) {
            cct_showch(76 - i, 14 + i - n, ' ', i, i, 2 * i + 1);
            Sleep(50);
        }
    }
    cct_setcolor(0, 7);
}

void display(char src,char dst)
{
    int X_start, Y_start, X_end, Y_end, pan;
    if (dst == 65) {
        X_end = 12;
        Y_end = topA;
        pan=A[topA-1];
        
    }
    else if (dst == 66) {
        X_end = 44;
        Y_end = topB;
        pan = B[topB-1];
    }
    else {
        X_end = 76;
        Y_end = topC;
        pan = C[topC-1];
    }
    if (src == 65) {
        X_start = 12;
        Y_start = topA+1;
    }  
    else if (src == 66) {
        X_start = 44;
        Y_start = topB+1;
    }
    else {
        X_start = 76;
        Y_start = topC+1;
    }
    cct_gotoxy(0, 38);
    for (int i = 15-Y_start; i > 1; i--) {
        cct_showch(X_start-pan, i, ' ', 0, 7, 2 * pan + 1);
        if(i>=3)
            cct_showch(X_start, i, ' ', 14, 14, 1);
        if (velocity != 5)
            Sleep(50);
        cct_showch(X_start-pan, i-1, ' ', pan, pan, 2 * pan + 1);
        if (velocity == 0)
            Sleep(50);
        else
            speed();
    }
    if (X_start < X_end) {
        for (int j = X_start; j < X_end; j++) {
            cct_showch(j-pan, 1, ' ', 0, 7, 2 * pan + 1);
            if (velocity != 5)
                Sleep(50);
            cct_showch(j-pan+1, 1, ' ', pan, pan, 2 * pan + 1);
            if (velocity == 0)
                Sleep(50);
            else
                speed();
        }
    }
    else if (X_start > X_end){
        for (int j = X_start; j > X_end; j--) {
            cct_showch(j-pan, 1, ' ', 0, 7, 2 * pan + 1);
            if (velocity != 5)
                Sleep(50);
            cct_showch(j-pan-1, 1, ' ', pan, pan, 2 * pan + 1);
            if (velocity == 0)
                Sleep(50);
            else
                speed();
        }
    }
    for (int k =1 ; k < 15-Y_end; k++) {
        cct_showch(X_end - pan, k, ' ', 0, 7, 2 * pan + 1);
        if(k>=3)
            cct_showch(X_end, k, ' ', 14, 14, 1);
        if (velocity != 5)
            Sleep(50);
        cct_showch(X_end - pan, k + 1, ' ', pan, pan, 2 * pan + 1);
        if (velocity == 0)
            Sleep(50);
        else
            speed();
    }
    cct_setcolor(0, 7);
}

void step(int src, int dst)
{
    int pan;
    if (src == 65) {
        pan = A[topA - 1];
        A[topA - 1] = 0;
        topA = topA - 1;
    }
    else if (src == 66) {
        pan = B[topB - 1];
        B[topB - 1] = 0;
        topB = topB - 1;
    }
    else {
        pan = C[topC - 1];
        C[topC - 1] = 0;
        topC = topC - 1;
    }
    if (dst == 65) {
        A[topA] = pan;
        topA++;
    }
    else if (dst == 66) {
        B[topB] = pan;
        topB++;
    }
    else {
        C[topC] = pan;
        topC++;
    }
}

void landscape()
{
    int i;
    cout << " A:";
    for (i = 0; i < 10; i++) {
        if (A[i] != 0)
            cout << setw(2) << A[i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (i = 0; i < 10; i++) {
        if (B[i] != 0)
            cout << setw(2) << B[i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (i = 0; i < 10; i++) {
        if (C[i] != 0)
            cout << setw(2) << C[i];
        else
            cout << "  ";
    }
}

void portrait(char order)
{
    int Y_zuobiao;
    if (order == '4')
        Y_zuobiao = 12;
    else
        Y_zuobiao = 27;
    cct_gotoxy(9, Y_zuobiao);
    cout << "=========================";
    cct_gotoxy(9, Y_zuobiao+1);
    cout << "  A         B         C  ";
    int i;
    for (i = 0; i < 10; i++) {
        cct_gotoxy(10, Y_zuobiao-1 - i);
        if (A[i] != 0)
            cout << setw(2) << A[i];
        else
            cout << "  ";
    }
    for (i = 0; i < 10; i++) {
        cct_gotoxy(20, Y_zuobiao-1 - i);
        if (B[i] != 0)
            cout << setw(2) << B[i];
        else
            cout << "  ";
    }
    for (i = 0; i < 10; i++) {
        cct_gotoxy(30, Y_zuobiao-1 - i);
        if (C[i] != 0)
            cout << setw(2) << C[i];
        else
            cout << "  ";
    }
}

void shouhang(char src, char dst, int n, char order) 
{
    if (order == '4' || order == '8')
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << velocity << endl;
    else
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
}

void detail(int n, char src, char tmp, char dst, char order)
{
    if(order=='1')
        cout << n << "# " << src << "---->" << dst << endl;
    else if (order == '2') {
        cout << "第" << setw(4) << num << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
        num++;
    }
    else if (order == '3') {
        cout << "第" << setw(4) << num << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
        num++;
        step(src, dst);
        landscape();
        cout << endl;
    }
    else if (order == '4')
    {
        speed();
        cct_gotoxy(0, 17);
        cout << "第" << setw(4) << num << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
        num++;
        step(src, dst);
        landscape();
        portrait(order);
    }
    else if (order == '8'|| order == '9') {
        if (order == '8')
            speed();
        cct_gotoxy(0, 32);
        cout << "第" << setw(4) << num << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
        num++;
        step(src, dst);
        landscape();
        portrait(order);
        display(src, dst);
    }
}

void hanoi(int n, char src, char tmp, char dst,char order)
{
    if (n == 1)
        detail(n, src, tmp, dst, order);
    else {
        hanoi(n - 1, src, dst, tmp,order);
        detail(n, src, tmp, dst, order);
        hanoi(n - 1, tmp, src, dst,order);
    }
}

void game(int n, char src, char tmp, char dst, char order)
{
    char start, end;
    char shuru[20] = {0};
    int pan;
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
    portrait(order);
    cct_gotoxy(0, 32);
    cout << "初始: ";
    landscape();
    column();
    disc(src, n);
    cct_gotoxy(0, 34);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
    int x, y;
    cct_getxy(x, y);
    while (1) {
        cct_showch(x, y, ' ', 0, 0, 20);
        cct_showch(0, y + 1, ' ', 0, 0, 25);
        cct_setcolor(0, 7);
        cct_gotoxy(x, y);
        int i=0;
        while (i < 20) {
            shuru[i] = _getch();
            if (shuru[i] == 13)
                break;
            else if (shuru[i] <= 32 || shuru[i] == 127)
                continue;
            cout << shuru[i];
            i++;
        }
        if (i > 2||i==0)
            continue;
        if (i == 1) {
            if (shuru[0] == 81 || shuru[0] == 113) {
                cct_gotoxy(0, y + 1);
                cout << "游戏中止!!!!!";
                return;
            }
            else
                continue;
        }
        start = shuru[0];
        end = shuru[1];
        if (start >= 97)
            start = start - 32;
        if (end >= 97)
            end = end - 32;
        if (start < 65 || start > 67|| end < 65 || end>67||start == end)
            continue;
        if (start == 65) {
            if (topA == 0) {
                cct_gotoxy(0, y + 1);
                cout << "源柱为空!";
                Sleep(500);
                continue;
            }

        }
        if (start == 66) {
            if (topB == 0) {
                cct_gotoxy(0, y + 1);
                cout << "源柱为空!";
                Sleep(500);
                continue;
            }
        }
        if (start == 67) {
            if (topC == 0) {
                cct_gotoxy(0, y + 1);
                cout << "源柱为空!";
                Sleep(500);
                continue;
            }
        }
        if (start == 65) {
            if (end == 66) {
                if (topB>0&&A[topA - 1] > B[topB - 1]) {
                    cct_gotoxy(0, y + 1);
                   
                    cout << "大盘压小盘，非法移动!";
                    Sleep(500);
                    continue;
                }
            }
            if (end == 67) {
                if (topC>0&&A[topA - 1] > C[topC - 1]) {
                    cct_gotoxy(0, y + 1);
                    cout << "#";
                    cout << "大盘压小盘，非法移动!";
                    Sleep(500);
                    continue;
                }
            }
            pan = A[topA - 1];
        }
        if (start == 66) {
            if (end == 65) {
                if (topA >0&&B[topB - 1] > A[topA - 1]) {
                    cct_gotoxy(0, y + 1);
                    cout << "大盘压小盘，非法移动!";
                    Sleep(500);
                    continue;
                }
            }
            if (end == 67) {
                if (topC>0&&B[topB - 1] > C[topC - 1]) {
                    cct_gotoxy(0, y + 1);
                    cout << "大盘压小盘，非法移动!";
                    Sleep(500);
                    continue;
                }
            }
            pan = B[topB - 1];
        }
        if (start == 67) {
            if (end == 66) {
                if (topB>0&&C[topC - 1] > B[topB - 1]) {
                    cct_gotoxy(0, y + 1);
                    cout << "大盘压小盘，非法移动!";
                    Sleep(500);
                    continue;
                }
            }
            if (end == 65) {
                if (topA>0&&C[topC - 1] > A[topA - 1]) {
                    cct_gotoxy(0, y + 1);
                    cout << "大盘压小盘，非法移动!";
                    Sleep(500);
                    continue;
                }
            }
            pan = C[topC - 1];
        }
        detail(pan, start, tmp,end, order);
        if (end == 65) {
            if (topA == n) {
                cct_gotoxy(0, y + 1);
                cout << "游戏结束!!!!!";
                return;
            }

        }
        if (end == 66) {
            if (topB == n) {
                cct_gotoxy(0, y + 1);
                cout << "游戏结束!!!!!";
                return;
            }
        }
        if (end == 67) {
            if (topC == n) {
                cct_gotoxy(0, y + 1);
                cout << "游戏结束!!!!!";
                return;
            }
        }
    }
}

void input(char* src, char* dst, char* tmp, int* n, char order) {
    int i;
    cout << endl;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        if (cin.fail() || *n > 10 || *n < 1) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else {
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.fail() || *src > 99 || *src < 65 || *src < 97 && *src>67) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else {
            if (*src > 96)
                *src = *src - 32;
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        if (cin.fail() || *dst > 99 || *dst < 65 || *dst < 97 && *dst>67) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else {
            if (*dst > 96)
                *dst = *dst - 32;
            if (*src == *dst) {
                cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
                cin.clear();
                cin.ignore(2147483647, '\n');
                continue;
            }
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    if (*src == 65 && *dst == 66 || *src == 66 && *dst == 65)
        *tmp = 67;
    else if (*src == 65 && *dst == 67 || *src == 67 && *dst == 65)
        *tmp = 66;
    else if (*src == 66 && *dst == 67 || *src == 67 && *dst == 66)
        *tmp = 65;
    for (i = 0; i < *n; i++) {
        if (*src == 65)
            A[i] = *n - i;
        else if (*src == 66)
            B[i] = *n - i;
        else
            C[i] = *n - i;
    }
    if (*src == 65)
        topA = *n;
    else if (*src == 66)
        topB = *n;
    else
        topC = *n;
    if (order == '4' || order == '8') {
        while (1) {
            cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
            cin >> velocity;
            if (cin.fail() || velocity > 5 || velocity < 0) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                continue;
            }
            else {
                cin.clear();
                cin.ignore(2147483647, '\n');
                break;
            }
        }
    }
}