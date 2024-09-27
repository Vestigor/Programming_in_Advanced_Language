/* 信05 2353814 马小龙 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare(char str1[], char str2[])
{
	int ret = 0;
	for (int k = 0; k < 7;k++) {
		if (str1[k] > str2[k])
			ret++;
		if (str1[k] < str2[k]&&ret==0)
			return 1;
	}
	return 0;
}

int input(char xuehao[], char name[],int i)
{
	int grade;
	printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
	scanf("%s %s %d", xuehao, name, &grade);
	return grade;
}

void output(char xuehao[][8], char name[][9], int grade[])
{
	printf("\n");
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++) {
		if (grade[i]>=60)
			printf("%s %s %d\n",  name[i], xuehao[i], grade[i]);
	}
}

void my_rank(char xuehao[][8], char name[][9], int grade[])
{
	int i, j, k, t;
	char a, b;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (compare(xuehao[j],xuehao[j+1])) {
				for (k = 0; k < 8; k++) {
					a = xuehao[j][k];
					xuehao[j][k] = xuehao[j + 1][k];
					xuehao[j + 1][k] = a;
				}
				for (k = 0; k < 9; k++) {
					b = name[j][k];
					name[j][k] = name[j + 1][k];
					name[j + 1][k] = b;
				}
				t = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = t;
			}
		}
	}
}

int main()
{
	char xuehao[10][8], name[10][9];
	int grade[10], i;
	for (i = 0; i < 10; i++)
		grade[i] = input(xuehao[i], name[i], i);
	my_rank(xuehao, name, grade);
	output(xuehao, name, grade);
	
	return 0;
}