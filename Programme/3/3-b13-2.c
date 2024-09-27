/* 信05 2353814 马小龙 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int y, m, d, n, i, j, ret1, ret2;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1 = scanf("%d%d", &y,&m);
		if (ret1!=2) {
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n')
				;
			continue;
		}
		if (y < 2000 || y > 2030) {
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (m < 1 || m > 12) {
			printf("输入非法，请重新输入\n");
			continue;
		}
		break;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		n = 31;
	else if (m == 2) {
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			n = 29;
		else
			n = 28;
	}
	else
		n = 30;
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", y, m);
		ret2 = scanf("%d", &d);
		if (ret2!=1) {
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n')
				;
			continue;
		}
		if (d < 0 || d > 7) {
			printf("输入非法，请重新输入\n");
			continue;
		}
		printf("\n");
		break;
	}
	printf("%d年%d月的月历为:\n", y, m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	for (i = 1; i <= d; i++) {
		if (i == 1)
			printf("    ");
		else
			printf("        ");
	}
	for (j = 1; j <= n; j++) {
		if ((d + j - 1) % 7 == 0)
			printf("%4d", j);
		else
			printf("%8d", j);
		if ((d + j) % 7 == 0)
			printf("    \n");
		if ((d + j) % 7 != 0 && j == n)
			printf("    ");
	}
	printf("\n");

	return 0;
}