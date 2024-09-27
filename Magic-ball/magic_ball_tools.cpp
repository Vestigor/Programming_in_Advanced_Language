/* 2353814 马小龙 信05 */
#include <iostream>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

int End_judge(int a[][9],int time,char order)
{
	int num = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (a[i][j] != 0)
				num++;
	
	if (order == '1') {
		if (num == 0)
			cout << "初始已无可消除项" << endl;
		return 1;
	}
	else if (order == '2'|| order == '3') {
		if (num == 0) {
			if (time == 0 && order=='2')
				cout << "初始无可消除项，本小题无法测试，请再次运行" << endl;
			else
				cout << "初始已无可消除项" << endl;
			return 1;
		}
	}
	else if(order=='4'||order=='5')
		return 1;
	else if (order == '6') {
		if (num == 0)
			cout << "(未找到初始可消除项)" << endl;
		return 1;
	}
	else if (order == '7') {
		if (num == 0) {
			if (time == 0) {
				cct_gotoxy(14,0);
				cout << "(未找到初始可消除项)";
			}
			return 1;
		}
	}
	else if (order == '8') {
		if (num == 0)
		    return 1;
	}
	else if (order == '9') {
		if (num == 0)
			return 1;
	}

	return 0;
}

int mouse_read_judge(int* array[][9], int row, int column,int read_I[],int read_J[])
{
	int judge_array[9][9] = { 0 }, judge_a[9][9]={ 0 }, * judge_parray[9][9], * judge_pa[9][9], ret, num = 0;
	if (read_I[0] == read_I[1] && read_J[0] == read_J[1])
		return -1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			judge_parray[i][j] = &judge_array[i][j];
			judge_pa[i][j] = &judge_a[i][j];
			judge_array[i][j] = *array[i][j];
		}
	}
	ret = judge_array[read_I[0]][read_J[0]];
	judge_array[read_I[0]][read_J[0]] = judge_array[read_I[1]][read_J[1]];
	judge_array[read_I[1]][read_J[1]] = ret;
	judge(judge_parray, row, column, judge_pa);
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < column; j++) 
			if (judge_a[i][j] != 0)
				num++;
	if (num != 0)
		return 0;
	else
		return 1;
}