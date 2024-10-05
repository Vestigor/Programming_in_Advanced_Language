/* 2353814 马小龙 信05 */
#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;


int score_counter(int *pa[][9],int row,int column)
{
	int num = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (*pa[i][j] != 0)
				num++;
	return num;
}

int mouse_read(int* array[][9], int* pa[][9], char order,int interval,int hang,int* pread_I[2] = { 0 },int* pread_J[2]={0})
{
	cct_enable_mouse();
	int X, Y, I, J,N=0;
	int Action, keycode1, keycode2;
	while (1) {
		int ret=cct_read_keyboard_and_mouse(X, Y, Action, keycode1, keycode2);
		double dI = (Y - 2.0) / (interval / 2);
		double dJ = (X - 2.0) / interval;
		I = int(dI);
		J = int(dJ);
		cct_showch(0, hang - 3, ' ', COLOR_BLACK, COLOR_WHITE, 40);
		cct_gotoxy(0, hang - 3);
		if ((I == dI || I == dI - 0.5) && (J == dJ || J == dJ - 0.25) && (I >= 0 && I <= 8) && (J >= 0 && J <= 8)) {
			cout <<"[当前光标] "<< char(65 + I) << "行" << J + 1 << "列";
			if (Action == MOUSE_LEFT_BUTTON_CLICK) {
				cct_showch(0, hang - 3, ' ', COLOR_BLACK, COLOR_WHITE, 40);
				cct_gotoxy(0, hang - 3);
				if (*array[I][J] == *pa[I][J]) {
					cout << "当前选择" << char(65 + I) << "行" << J + 1 << "列";
					*pread_I[N] = I;
					*pread_J[N] = J;
					if (N == 1) {
						if ((*pread_I[1] - *pread_I[0])* (*pread_I[1] - *pread_I[0])+ (*pread_J[1]- *pread_J[0])*(*pread_J[1] - *pread_J[0])>1) {
							cct_showstr(2 + *pread_J[0] * interval, 2 + *pread_I[0] * interval / 2, "◎", *array[*pread_I[0]][*pread_J[0]], COLOR_BLACK, 1, -1);
							N = 0;
							*pread_I[N] = I;
							*pread_J[N] = J;
						}
					}
					cct_showstr(2 + J * interval, 2 + I * interval / 2, "◎", *array[I][J], COLOR_HWHITE, 1, -1);
					N++;
					if (order == '8') {
						Sleep(500);
						break;
					}
				}
				else
					cout << "不能选择" << char(65 + I) << "行" << J + 1 << "列";
			}
			else if (Action == MOUSE_RIGHT_BUTTON_CLICK)
				return 1;
			if (N == 2)
				break;
		}
		else
			cout << "[当前光标] 位置非法";
	}
	cct_disable_mouse();
	return 0;
}

void pause_judge()
{
	while (1) {
		int ret = _getch();
		if (ret == '\n' || ret == '\r')
			break;
	}
}

int equal_num(int *array[][9],int row, int column, int *pa[][9])
{
	int ret = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (*pa[i][j] != 0)
				ret++;
	return ret;
}

void hint(int* array[][9],int row,int column ,int* pa[][9],char order)
{
	int A[13][13] = { 0 }, B[13][13] = {0};
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			A[i + 2][j + 2] = *array[i][j];
	for (int i = 2; i < row + 2; i++) {
		for (int j = 2; j < column + 2; j++) {
			if (A[i][j - 1] == A[i][j + 1] && A[i][j - 1] != 0) {
				if (A[i + 1][j] == A[i][j - 1]) {
					B[i + 1][j] = A[i + 1][j];
					B[i][j] = A[i][j];
				}
				if (A[i - 1][j] == A[i][j - 1]) {
					B[i - 1][j] = A[i - 1][j];
					B[i][j] = A[i][j];
				}
			}
			if (A[i - 1][j] == A[i + 1][j] && A[i - 1][j] != 0) {
				if (A[i][j + 1] == A[i - 1][j]) {
					B[i][j + 1] = A[i][j + 1];
					B[i][j] = A[i][j];
				}
				if (A[i][j - 1] == A[i - 1][j]) {
					B[i][j - 1] = A[i][j - 1];
					B[i][j] = A[i][j];
				}
			}
			if (A[i][j - 2] == A[i][j - 1] && A[i][j - 1] != 0) {
				if (A[i][j + 1] == A[i][j - 1]) {
					B[i][j + 1] = A[i][j + 1];
					B[i][j] = A[i][j];
				}
				if (A[i+1][j] == A[i][j - 1]) {
					B[i + 1][j] = A[i+1][j];
					B[i][j] = A[i][j];
				}
				if (A[i-1][j] == A[i][j - 1]) {
					B[i - 1][j] = A[i-1][j];
					B[i][j] = A[i][j];
				}
			}
			if (A[i][j + 2] == A[i][j + 1] && A[i][j + 1] != 0) {
				if (A[i][j - 1] == A[i][j + 1]) {
					B[i][j - 1] = A[i][j -1];
					B[i][j] = A[i][j];
				}
				if (A[i + 1][j] == A[i][j + 1]) {
					B[i + 1][j] = A[i + 1][j];
					B[i][j] = A[i][j];
				}
				if (A[i - 1][j] == A[i][j + 1]) {
					B[i - 1][j] = A[i - 1][j];
					B[i][j] = A[i][j];
				}
			}
			if (A[i-2][j] == A[i-1][j] && A[i-1][j] != 0) {
				if (A[i+1][j] == A[i - 1][j]) {
					B[i + 1][j] = A[i+1][j];
					B[i][j] = A[i][j];
				}
				if (A[i][j+1] == A[i - 1][j]) {
					B[i][j + 1] = A[i][j + 1];
					B[i][j] = A[i][j];
				}
				if (A[i][j-1] == A[i - 1][j]) {
					B[i][j - 1] = A[i][j - 1];
					B[i][j] = A[i][j];
				}
			}
			if (A[i + 2][j] == A[i + 1][j] && A[i + 1][j] != 0) {
				if (A[i - 1][j] == A[i + 1][j]) {
					B[i - 1][j] = A[i - 1][j];
					B[i][j] = A[i][j];
				}
				if (A[i][j + 1] == A[i + 1][j]) {
					B[i][j + 1] = A[i][j + 1];
					B[i][j] = A[i][j];
				}
				if (A[i][j - 1] == A[i + 1][j]) {
					B[i][j - 1] = A[i][j - 1];
					B[i][j] = A[i][j];
				}
			}
		}
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			*pa[i][j] = B[i + 2][j + 2];
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	int min = 3;
	if (strlen(s1) < 3)
		return -1;
	char f1 = 0, f2 = 0;
	for (int i = 0; i < min; i++) {
		if (s1[i] >= 65 && s1[i] <= 90)
			f1 = s1[i] + 32;
		else
			f1 = s1[i];
		if (s2[i] >= 65 && s2[i] <= 90)
			f2 = s2[i] + 32;
		else
			f2 = s2[i];
		if (f1 != f2)
			return int(f1 - f2);
	}
	return 0;
}

void fall(int *array[][9],int row,int column, int* pa[][9],char order)
{
	int ret_array;
	cout << endl;
	if (order >= '7')
		climinate(array, row, column, pa);
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			if (*array[j][i] == *pa[j][i]) {
				*array[j][i] = 0;
				*pa[j][i] = 0;
			}
		}
	}
	for (int i = 0; i<column ; i++) {
		for (int j = 0; j <row; j++) {
			for(int k =0;k<row-j-1;k++)
			if (*array[k][i] != 0&& *array[k+1][i]==0) {
				if (order >= '7')
					cartoon_fall(array, pa, i, k);
				ret_array = *array[k][i];
				*array[k][i] = *array[k + 1][i];
				*array[k + 1][i] = ret_array;
			}
		}
	}
}

void fill(int* array[][9], int row, int column, int* pa[][9],char order)
{
	cout << endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (*array[i][j] == *pa[i][j]) {
				*array[i][j] = rand() % 9 + 1;
				*pa[i][j] = *array[i][j];
				if (order >= '7')
					pad(array, pa, j, i);
			}
		}
	}
}

void judge(int* array[][9], int row, int column, int* pa[][9])
{
	int num;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int k = j + 1;
			num = 1;
			for (; k < column; k++) {
				if (*array[i][k] == *array[i][j])
					num++;
				else
					break;
			}
			if (num >= 3)
				for (int n = j; n < j + num; n++)
					*pa[i][n] = *array[i][n];
			j += (num - 1);
		}
	}
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			int k = j + 1;
			num = 1;
			for (; k < row; k++) {
				if (*array[k][i] == *array[j][i])
					num++;
				else
					break;
			}
			if (num >= 3)
				for (int n = j; n < j + num; n++)
					*pa[n][i] = *array[n][i];
			j += (num - 1);
		}
	}
}

void tabulation(int *array[][9], int row, int column,int* pa[][9],int inst)
{
	switch (inst) {
		case 0:
			cout << "初始数组：" << endl;
			break;
		case 1:
			cout << "初始可消除项（不同色标识）：" << endl;
			break;
		case 2:
			cout << "下落除0后的数组(不同色标识)：" << endl;
			break;
		case 3:
			cout << "新值填充后的数组(不同色标识)：" << endl;
			break;
		case 4:
			cout << "可选择的消除提示（不同色标识）：" << endl;
			break;
	}
	cout << "  | ";
	for (int i = 1; i <= column; i++)
		cout << " " << i << " ";
	cout << endl;
	cout<<"--+-"<< setfill('-') << setw(3*column) << "-" << endl;
	for (int i = 0; i < row; i++) {
		cout << char(65 + i) << " | ";
		for (int j = 0; j < column; j++) {
			if (*array[i][j] == *pa[i][j]) {
				cout << " ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
				cout << *array[i][j];
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << " ";
			}
			else
			    cout << " " << *array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void initial(int* array[][9], int row, int column)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			*array[i][j] = 0;
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			*array[i][j] = rand() % 9 + 1;
	}
}

void input(int *prow,int *pcolumn)
{
	while (1) {
		cout << "请输入行数(5-9)：" << endl;
		cin >> *prow;
		if (cin.fail() != 0 || *prow < 5 || *prow > 9) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "请输入列数(5-9)：" << endl;
		cin >> *pcolumn;
		if (cin.fail() != 0 || *pcolumn < 5 || *pcolumn > 9) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		break;
	}
	cin.clear();
	cin.ignore(2147483647, '\n');
	cout << endl;
}

void base(int* array[][9], int row, int column, char order)
{
	int a[9][9] = { 0 }, X, Y, time = 0;
	int* pa[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			pa[i][j] = &a[i][j];
	char str[200], s[] = "END";
	tabulation(array, row, column, pa, 0);
	cout << "按回车键进行寻找初始可消除项的操作...";
	pause_judge();
	cout << endl;
	while (1) {
		judge(array, row, column, pa);
		if (equal_num(array,row,column, pa)) {
			tabulation(array, row, column, pa, 1);
			if (order != '1') {
				cout << "按回车键进行数组下落除0操作...";
				pause_judge();
				fall(array, row, column, pa,order);
				tabulation(array, row, column, pa, 2);
				cout << "按回车键进行新值填充...";
				pause_judge();
				fill(array, row, column, pa,order);
				tabulation(array, row, column, pa, 3);
			}
		}
		if (End_judge(a, time, order) == 1)
			break;
		time++;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				a[i][j] = 0;
	}
	if (order == '3') {
		hint(array, row, column, pa, order);
		tabulation(array, row, column, pa, 4);
	}
	cout << "本小题结束，请输入End继续...";
	cct_getxy(X, Y);
	while (1) {
		cin.getline(str, 200,'\n');
		if (tj_strcasecmp(str, s) != 0) {
			cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 3);
			cct_gotoxy(0, Y + 1);
			cout << "输入错误，请重新输入" << endl;
			cct_gotoxy(X, Y);
		}
		else
			break;
	}
}

void graph(int* array[][9], int row, int column, char order)
{
	int a[9][9] = { 0 }, col, line, buffer_col, buffer_line, hang[2] = { row + 6,2 * row + 5 }, lie = 40, N = 1;
	int* pa[9][9], time = 0,score=0;
	char str[200], s[] = "END";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			pa[i][j] = &a[i][j];
	if (order == '4' || order == '5') {
		tabulation(array, row, column, pa, 1);
		cout << "按回车键显示图形...";
		pause_judge();
	}
	cct_cls();
	if (order >= '6' && order <= '8')
		judge(array, row, column, pa);
	frame(row, column, order, &col, &line, &buffer_col, &buffer_line);
	ball(array, row, column, pa, order, 1);
	cct_gotoxy(0, 0);
	if (order == '4' || order == '6')
		N = 0;
	cout << "屏幕：" << hang[N] << "行" << lie << "列";
	while (1) {
		if (order == '7') {
			cct_gotoxy(11, 0);
			cout << "(当前分数：" << score << " 右键退出)";
		}
		if (End_judge(a, time, order))
			break;
		cct_gotoxy(0, hang[N] - 3);
		if (order < '8') {
			cout << "按回车键进行数组下落除0操作...";
			pause_judge();
		}
		fall(array, row, column, pa, order);
		cct_gotoxy(0, hang[N] - 3);
		if (order < '8') {
			cout << "按回车键进行新值填充...       ";
			pause_judge();
		}
		fill(array, row, column, pa, order);
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				a[i][j] = 0;
		judge(array, row, column, pa);
		time++;
		ball(array, row, column, pa, order, 1);
	}
	if (order == '7' || order == '8') {
		hint(array, row, column, pa, order);
		ball(array, row, column, pa, order);
	}
	int read_I[2] = { 0 }, read_J[2] = { 0 },* pread_I[2],* pread_J[2];
	for (int i = 0; i < 2; i++) {
		pread_I[i] = &read_I[i];
		pread_J[i] = &read_J[i];
	}
	if (order == '8')
		mouse_read(array, pa, order ,4,hang[N], pread_I, pread_J);
	cct_showch(0, hang[N] - 3, ' ', COLOR_BLACK, COLOR_WHITE, 40);
	cct_gotoxy(0, hang[N] - 3);
	while (1) {
		cout << "本小题结束，请输入End继续...";
		cin.getline(str,200,'\n');
		if (tj_strcasecmp(str, s) != 0)
			continue;
		else
			break;
	}
	cct_setconsoleborder(col, line, buffer_col, buffer_line);
	cct_setfontsize("新宋体", 16, 8);
}

void game(int* array[][9], int row, int column,char order)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int a1[9][9] = { 0 },a2[9][9]={0}, col, line, buffer_col, buffer_line, hang = 2 * row + 5, lie = 40;
	int* pa1[9][9],*pa2[9][9], time = 0, score = 0;
	char str[200], s[] = "END";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			pa1[i][j] = &a1[i][j];
			pa2[i][j] = &a2[i][j];
		}
	}
	cct_cls();
    judge(array, row, column, pa1);
	frame(row, column, order, &col, &line, &buffer_col, &buffer_line);
	ball(array, row, column, pa1, order, 1);
	cct_gotoxy(0, 0);
	cout << "屏幕：" << hang << "行" << lie << "列";
	cout << "(当前分数：" << score << " )";
	while (1) {
		if (End_judge(a1, time, order)==1) {
			int ret;
			hint(array, row, column, pa2, order);
			ball(array, row, column, pa2, order);
			if (End_judge(a2, time, order) == 1) {
				cct_showch(0, 0, ' ', COLOR_BLACK, COLOR_WHITE, 40);
				cct_gotoxy(0, 0);
				cout << "无可消除项，游戏结束！最终分数：" << score << ")";
				break;
			}
			while (1) {
				cct_gotoxy(14, 0);
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << "(当前分数：" << score << " 右键退出)";
				int read_I[2] = { 0 }, read_J[2] = { 0 }, * pread_I[2], * pread_J[2];
				for (int i = 0; i < 2; i++) {
					pread_I[i] = &read_I[i];
					pread_J[i] = &read_J[i];
				}
				ret = mouse_read(array, pa2, order, 4, hang, pread_I, pread_J);
				if (ret == 0) {
					if (mouse_read_judge(array, row, column, read_I, read_J) == -1) {
						ball(array, row, column, pa2, order);
						continue;
					}
					else if (mouse_read_judge(array, row, column, read_I, read_J) == 1) {
						cct_showch(0, hang - 3, ' ', COLOR_BLACK, COLOR_WHITE, 40);
						cct_gotoxy(0, hang - 3);
						cout<<"不能交换"<< char(65 + read_I[1]) << "行" << read_J[1] + 1 << "列<=>"<< char(65 + read_I[0]) << "行" << read_J[0] + 1 << "列";
						ball(array, row, column, pa2, order);
						Sleep(100);
						continue;
					}
					else {
						int tmp = *array[read_I[0]][read_J[0]];
						*array[read_I[0]][read_J[0]] = *array[read_I[1]][read_J[1]];
						*array[read_I[1]][read_J[1]] = tmp;
					}
				}
				break;
			}
			if (ret == 1)
				break;
			judge(array, row, column, pa1);
			ball(array, row, column, pa1, order, 1);
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					*pa2[i][j] = 0;
			time++;
		}
		if (time >= 1)
			score =score + score_counter(pa1, row, column);
		fall(array, row, column, pa1, order);
		fill(array, row, column, pa1, order);
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				a1[i][j] = 0;
		judge(array, row, column, pa1);
		ball(array, row, column, pa1, order, 1);
	}
	
	cct_showch(0, hang - 3, ' ', COLOR_BLACK, COLOR_WHITE, 40);
	cct_gotoxy(0, hang - 3);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	while (1) {
		cout << "本小题结束，请输入End继续...";
		cin.getline(str, 200,'\n');
		if (tj_strcasecmp(str, s) != 0)
			continue;
		else
			break;
	}
	cct_setconsoleborder(col, line, buffer_col, buffer_line);
	cct_setfontsize("新宋体", 16, 8);
}