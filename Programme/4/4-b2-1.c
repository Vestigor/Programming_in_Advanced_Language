/* 信05 2353814 马小龙 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d) {
	int w, c;
	if (m == 1 || m == 2) {
		m = m + 12;
		y = y - 1;
	}
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	while (w < 0)
		w = w + 7;
	w = w % 7;
	return w;
}
int main()
{
	int year, month, day, week, ret;
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d%d%d", &year, &month, &day);
		if (ret!=3) {
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n')
				;
			continue;
		}
		if (year < 1900 || year > 2100) {
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (month < 1 || month > 12) {
			printf("月份不正确，请重新输入\n");
			continue;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 1 || day>31) {
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 1 || day>30) {
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		else {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (day < 0 || day>29) {
					printf("日不正确，请重新输入\n");
					continue;
				}
			}
			else {
				if (day < 0 || day>28) {
					printf("日不正确，请重新输入\n");
					continue;
				}
			}
		}
		break;
	}
	week = zeller(year, month, day);
	if (week == 1)
		printf("星期一\n");
	else if (week == 2)
		printf("星期二\n");
	else if (week == 3)
		printf("星期三\n");
	else if (week == 4)
		printf("星期四\n");
	else if (week == 5)
		printf("星期五\n");
	else if (week == 6)
		printf("星期六\n");
	else
		printf("星期日\n");

	return 0;
}