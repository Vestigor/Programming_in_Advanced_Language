/* 2353814 马小龙 信05 */
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;



void jx(char order)
{
	if (order == '4' || order == '5')
		Sleep(10);
}

void climinate(int* array[][9], int row, int column, int* pa[][9])
{
	int interval = 4;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (*array[i][j] == *pa[i][j]) {
				cct_showstr(2 + j * interval, 2 + i * interval / 2, "¤", *array[i][j], COLOR_BLACK, 1, -1);
				Sleep(100);
				cct_showch(2 + j * interval, 2 + i * interval / 2, ' ', COLOR_HWHITE, COLOR_BLACK,  2);
				Sleep(100);
			}
		}
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void cartoon_fall(int* array[][9], int* pa[][9],int X,int Y)
{
	int interval = 4;
	cct_showch(2 + X * interval, 2 + Y * interval / 2, ' ', COLOR_HWHITE, COLOR_BLACK, 2);
	cct_showstr(2 + X * interval, 2 + (Y+1) * interval / 2, "○", *array[Y][X], COLOR_BLACK, 1, -1);
	Sleep(100);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void pad(int* array[][9], int* pa[][9], int X, int Y)
{
	int interval = 4;
	cct_showstr(2 + X * interval, 2 + Y * interval / 2, "○", *array[Y][X], COLOR_BLACK, 1, -1);
	Sleep(100);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void ball(int* array[][9], int row, int column, int* pa[][9], char order,int ins)
{
	int interval[2] = { 2,4 }, N;
	if (order == '4' || order == '6')
		N = 0;
	else
		N = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (*array[i][j] == *pa[i][j]) {
				if(ins==1)
				    cct_showstr(2 + j * interval[N], 2 + i * interval[N] / 2, "●", *array[i][j], COLOR_BLACK, 1, -1);
				else
					cct_showstr(2 + j * interval[N], 2 + i * interval[N] / 2, "◎", *array[i][j], COLOR_BLACK, 1, -1);
			}
			else
			    cct_showstr(2+j* interval[N], 2+i* interval[N]/2, "○", *array[i][j], COLOR_BLACK, 1, -1);
			jx(order);
		}
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void frame(int row, int column, char order,int*pcol,int *pline,int *pbuffer_col,int *pbuffer_line)
{
	int interval[2] = { 2,4 }, N;
	cct_getconsoleborder(*pcol,*pline,*pbuffer_col,*pbuffer_line);
	int hang[2] = { row + 6,2 * row + 6 }, lie = 40;
	if (order == '4' || order == '6') 
		N = 0;
	else 
		N = 1;
	cct_setconsoleborder(lie, hang[N], lie, hang[N]);
	cct_setfontsize("新宋体", 28, 14);
	cct_showstr(0, 1, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	jx(order);
	for (int i = 0; i < column; i++) {
		cct_showstr(2 + interval[N] * i, 1, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		jx(order);
		if (order != '4' && order != '6'&& i + 1 < column) {
			cct_showstr(interval[N] * (i + 1), 1, "╦", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			jx(order);
		}
	}
	if(order != '4' && order != '6')
		cct_showstr(interval[N] * column, 1, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	else
		cct_showstr(2+interval[N] * column, 1, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	jx(order);
	for (int i = 0; i < row; i++) {
		cct_showstr(0, 2 + i * interval[N] / 2, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int j = 0; j < column; j++) {
			cct_showch(2 + interval[N] * j, 2 + i* interval[N] / 2, ' ', COLOR_HWHITE, COLOR_BLACK, 2);
			jx(order);
			if (order != '4' && order != '6') {
				cct_showstr(interval[N] * (j + 1), 2 + i * interval[N] / 2, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				jx(order);
			}
		}
		if (order == '4' || order == '6') {
			cct_showstr(interval[N] * column + 2, 2 + i * interval[N] / 2, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			jx(order);
		}
		if (i + 1 < row) {
			if (order != '4' && order != '6') {
				cct_showstr(0, 3 + i * interval[N] / 2, "╠", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				jx(order);
				for (int j = 0; j < column; j++) {
					cct_showstr(2 + interval[N] * j, 3 + i * interval[N] / 2, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					jx(order);
					if (j + 1 < column) {
						cct_showstr(interval[N] * (j + 1), 3 + i * interval[N] / 2, "╬", COLOR_HWHITE, COLOR_BLACK, 1, -1);
						jx(order);
					}
				}
				cct_showstr(interval[N] * column, 3 + i * interval[N] / 2, "╣", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				jx(order);
			}
		}
	}
	if (order == '4' || order == '6') {
		cct_showstr(0, 2 + row * interval[N] / 2, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		jx(order);
		for (int i = 0; i < column; i++) {
			cct_showstr(2 + i * interval[N], 2 + row * interval[N] / 2, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			jx(order);
		}
		cct_showstr(2 + interval[N] * column, 2 + row * interval[N] / 2, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		jx(order);
	}
	else {
		cct_showstr(0, 1 + row * interval[N] / 2, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		jx(order);
		for (int i = 0; i < column; i++) {
			cct_showstr(2 + i * interval[N], 1 + row * interval[N] / 2, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			jx(order);
			if (i + 1 < column) {
				cct_showstr(interval[N] * (i + 1), 1 + row * interval[N] / 2, "╩", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				jx(order);
			}
		}
		cct_showstr(interval[N] * column, 1 + row * interval[N] / 2, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		jx(order);
	}
}