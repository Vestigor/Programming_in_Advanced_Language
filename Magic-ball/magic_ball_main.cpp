/* 2353814 马小龙 信05 */
#include <iostream>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

int main()
{
	cct_setconsoleborder(120, 30, 120, 200);
	cct_setfontsize("新宋体", 16, 8);
	char order;
	int row, column, a[9][9] = { 0 };
	int* array[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			array[i][j] = &a[i][j];
	while (1) {
		menu(&order);
		if (order == '0')
			break;
		cct_cls();
		input(&row, &column);
		initial(array, row, column);
		switch (order) {
			case '1':
			case '2':
			case '3':
				base(array, row, column, order);
				break;
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
				graph(array, row, column, order);
				break;
			case '9':
				game(array, row, column, order);
				break;
		}
		cct_cls();
	}
	
	return 0;
}