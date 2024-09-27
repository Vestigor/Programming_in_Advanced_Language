/* 信05 2353814 马小龙*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int i, j, k, a = 1, n, i1, i2, i3, j1, j2, j3, k1, k2, k3, b = 0;
	for (i = 100; i < 1000; i++) {
		i1 = i / 100;
		i2 = i % 100 / 10;
		i3 = i % 10;
		if (i1 == i2 || i1 == i3 || i2 == i3 || i1 * i2 * i3 == 0)
			continue;
		for (j = i + 1; j < 1000; j++) {
			j1 = j / 100;
			j2 = j % 100 / 10;
			j3 = j % 10;
			if (j1 == j2 || j1 == j3 || j2 == j3 || j1 == i1 || j1 == i2 || j1 == i3 || j2 == i1 || j2 == i2 || j2 == i3 || j3 == i1 || j3 == i2 || j3 == i3 || j1 * j2 * j3 == 0)
				continue;
			for (k = j + 1; k < 1000; k++) {
				k1 = k / 100;
				k2 = k % 100 / 10;
				k3 = k % 10;
				if (k1 == k2 || k1 == k3 || k2 == k3 || k1 * k2 * k3 == 0)
					continue;
				else if (k1 == i1 || k1 == i2 || k1 == i3 || k1 == j1 || k1 == j2 || k1 == j3)
					continue;
				else if (k2 == i1 || k2 == i2 || k2 == i3 || k2 == j1 || k2 == j2 || k2 == j3)
					continue;
				else if (k3 == i1 || k3 == i2 || k3 == i3 || k3 == j1 || k3 == j2 || k3 == j3)
					continue;
				n = i + j + k;
				if (n == 1953) {
					printf("No.%3d : %d+%d+%d=%d\n",a,i,j,k,n);
					a++;
					b++;
				}
			}
		}
	}
	printf("total=%d\n", b);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}