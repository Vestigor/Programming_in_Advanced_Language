/* 2353814 马小龙 信05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[1000], i, j, k, t, max, sum=0, num, a = 101;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (i = 0; i < 1000; i++) {
		scanf("%d", &score[i]);
		if (score[i] < 0)
			break;
	}
	if (score[1] < 0) {
		printf("无有效输入\n");
		return 0;
	}
	if (score[i] < 0)
		i = i - 1;
	printf("输入的数组为:\n");
	for (j = 0; j <= i; j++) {
		printf("%d ", score[j]);
		if ((j + 1) % 10 == 0 && j != i)
			printf("\n");
	}
	printf("\n");
	printf("分数与人数的对应关系为:\n");
	while (i > sum) {
		max = 0;
		num = 0;
		for (k = 0; k <= i; k++) {
			if (max < score[k] && score[k] < a)
				max = score[k];
		}
		for (t = 0; t <= i; t++) {
			if (score[t] == max)
				num++;
		}
		printf("%d %d\n", max, num);
		sum = sum + num;
		a = max;
	}
		
	return 0;
}