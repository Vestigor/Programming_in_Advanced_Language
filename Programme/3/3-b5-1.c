/*2353814 信05 马小龙*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入年，月，日\n");
	int y, m, d, n;
	scanf("%d %d %d", &y, &m, &d);
	if (m >= 1 && m <= 12) {
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
			if (m == 1) {
				if (d >= 1 && d <= 31) {
					n = d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 2) {
				if (d >= 1 && d <= 29) {
					n = 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 3) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 4) {
				if (d >= 1 && d <= 30) {
					n = 31 + 29 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 5) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 6) {
				if (d >= 1 && d <= 30) {
					n = 31 + 29 + 31 + 30 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 7) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 8) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 9) {
				if (d >= 1 && d <= 30) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 10) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 11) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 12) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}

		}
		else {
			if (m == 1) {
				if (d >= 1 && d <= 31) {
					n = d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 2) {
				if (d >= 1 && d <= 28) {
					n = 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 3) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 4) {
				if (d >= 1 && d <= 30) {
					n = 31 + 28 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 5) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 6) {
				if (d >= 1 && d <= 30) {
					n = 31 + 28 + 31 + 30 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 7) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 8) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 9) {
				if (d >= 1 && d <= 30) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 10) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 11) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}
			if (m == 12) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
				}
				else
					printf("输入错误-日与月的关系非法\n");
			}

		}

	}
	else
		printf("输入错误-月份不正确\n");

	return 0;
}