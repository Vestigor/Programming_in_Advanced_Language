/*2353814 ÐÅ05 ÂíÐ¡Áú*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	double n;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
	scanf("%lf", &n);
	a1 = (int)(n / 10) / 100000000;
	a2 = (int)(n / 10) % 100000000 / 10000000;
	a3 = (int)(n / 10) % 10000000 / 1000000;
	a4 = (int)(n / 10) % 1000000 / 100000;
	a5 = (int)(n / 10) % 100000 / 10000;
	a6 = (int)(n / 10) % 10000 / 1000;
	a7 = (int)(n / 10) % 1000 / 100;
	a8 = (int)(n / 10) % 100 / 10;
	a9 = (int)(n / 10) % 10;
	a10 = (int)(floor((n / 10 - floor(n / 10)) * 10));
	a11 = (int)(round((n - floor(n)) * 100)) / 10;
	a12 = (int)(round((n - floor(n)) * 100)) % 10;
	if (a1 != 0) {
		if (a1 == 1)
			printf("Ò¼");
		else if (a1 == 2)
			printf("·¡");
		else if (a1 == 3)
			printf("Èþ");
		else if (a1 == 4)
			printf("ËÁ");
		else if (a1 == 5)
			printf("Îé");
		else if (a1 == 6)
			printf("Â½");
		else if (a1 == 7)
			printf("Æâ");
		else if (a1 == 8)
			printf("°Æ");
		else if (a1 == 9)
			printf("¾Á");
		printf("Ê°");
		if (a2 == 0)
			printf("ÒÚ");
	}
	if (a2 != 0) {
		if (a2 == 1)
			printf("Ò¼");
		else if (a2 == 2)
			printf("·¡");
		else if (a2 == 3)
			printf("Èþ");
		else if (a2 == 4)
			printf("ËÁ");
		else if (a2 == 5)
			printf("Îé");
		else if (a2 == 6)
			printf("Â½");
		else if (a2 == 7)
			printf("Æâ");
		else if (a2 == 8)
			printf("°Æ");
		else if (a2 == 9)
			printf("¾Á");
		printf("ÒÚ");
	}
	if (a3 != 0) {
		if (a3 == 1)
			printf("Ò¼");
		else if (a3 == 2)
			printf("·¡");
		else if (a3 == 3)
			printf("Èþ");
		else if (a3 == 4)
			printf("ËÁ");
		else if (a3 == 5)
			printf("Îé");
		else if (a3 == 6)
			printf("Â½");
		else if (a3 == 7)
			printf("Æâ");
		else if (a3 == 8)
			printf("°Æ");
		else if (a3 == 9)
			printf("¾Á");
		printf("Çª");
		if (a4 == 0 && a5 == 0 && a6 == 0)
			printf("Íò");
	}
	if ((a1 != 0 || a2 != 0) && a3 == 0 && a4 != 0)
		printf("Áã");
	if (a4 != 0) {
		if (a4 == 1)
			printf("Ò¼");
		else if (a4 == 2)
			printf("·¡");
		else if (a4 == 3)
			printf("Èþ");
		else if (a4 == 4)
			printf("ËÁ");
		else if (a4 == 5)
			printf("Îé");
		else if (a4 == 6)
			printf("Â½");
		else if (a4 == 7)
			printf("Æâ");
		else if (a4 == 8)
			printf("°Æ");
		else if (a4 == 9)
			printf("¾Á");
		printf("°Û");
		if (a5 == 0 && a6 == 0)
			printf("Íò");
	}
	if ((a1 != 0 || a2 != 0 || a3 != 0) && a4 == 0 && a5 != 0)
		printf("Áã");
	if (a5 != 0) {
		if (a5 == 1)
			printf("Ò¼");
		else if (a5 == 2)
			printf("·¡");
		else if (a5 == 3)
			printf("Èþ");
		else if (a5 == 4)
			printf("ËÁ");
		else if (a5 == 5)
			printf("Îé");
		else if (a5 == 6)
			printf("Â½");
		else if (a5 == 7)
			printf("Æâ");
		else if (a5 == 8)
			printf("°Æ");
		else if (a5 == 9)
			printf("¾Á");
		printf("Ê°");
		if (a6 == 0)
			printf("Íò");
	}
	if ((a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0) && a5 == 0 && a6 != 0)
		printf("Áã");
	if (a6 != 0) {
		if (a6 == 1)
			printf("Ò¼");
		else if (a6 == 2)
			printf("·¡");
		else if (a6 == 3)
			printf("Èþ");
		else if (a6 == 4)
			printf("ËÁ");
		else if (a6 == 5)
			printf("Îé");
		else if (a6 == 6)
			printf("Â½");
		else if (a6 == 7)
			printf("Æâ");
		else if (a6 == 8)
			printf("°Æ");
		else if (a6 == 9)
			printf("¾Á");
		printf("Íò");
	}
	if (a7 != 0) {
		if (a7 == 1)
			printf("Ò¼");
		else if (a7 == 2)
			printf("·¡");
		else if (a7 == 3)
			printf("Èþ");
		else if (a7 == 4)
			printf("ËÁ");
		else if (a7 == 5)
			printf("Îé");
		else if (a7 == 6)
			printf("Â½");
		else if (a7 == 7)
			printf("Æâ");
		else if (a7 == 8)
			printf("°Æ");
		else if (a7 == 9)
			printf("¾Á");
		printf("Çª");
	}
	if ((a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) && a7 == 0 && a8 != 0)
		printf("Áã");
	if (a8 != 0) {
		if (a8 == 1)
			printf("Ò¼");
		else if (a8 == 2)
			printf("·¡");
		else if (a8 == 3)
			printf("Èþ");
		else if (a8 == 4)
			printf("ËÁ");
		else if (a8 == 5)
			printf("Îé");
		else if (a8 == 6)
			printf("Â½");
		else if (a8 == 7)
			printf("Æâ");
		else if (a8 == 8)
			printf("°Æ");
		else if (a8 == 9)
			printf("¾Á");
		printf("°Û");
	}
	if ((a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0) && a8 == 0 && a9 != 0)
		printf("Áã");
	if (a9 != 0) {
		if (a9 == 1)
			printf("Ò¼");
		else if (a9 == 2)
			printf("·¡");
		else if (a9 == 3)
			printf("Èþ");
		else if (a9 == 4)
			printf("ËÁ");
		else if (a9 == 5)
			printf("Îé");
		else if (a9 == 6)
			printf("Â½");
		else if (a9 == 7)
			printf("Æâ");
		else if (a9 == 8)
			printf("°Æ");
		else if (a9 == 9)
			printf("¾Á");
		printf("Ê°");
	}
	if ((a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0) && a9 == 0 && a10 != 0)
		printf("Áã");
	if (a10 != 0) {
		if (a10 == 1)
			printf("Ò¼");
		else if (a10 == 2)
			printf("·¡");
		else if (a10 == 3)
			printf("Èþ");
		else if (a10 == 4)
			printf("ËÁ");
		else if (a10 == 5)
			printf("Îé");
		else if (a10 == 6)
			printf("Â½");
		else if (a10 == 7)
			printf("Æâ");
		else if (a10 == 8)
			printf("°Æ");
		else if (a10 == 9)
			printf("¾Á");
	}
	if (n == 0)
		printf("ÁãÔ²");
	if((int)n!=0)
	    printf("Ô²");
	if (a11 != 0) {
		if (a11 == 1)
			printf("Ò¼");
		else if (a11 == 2)
			printf("·¡");
		else if (a11 == 3)
			printf("Èþ");
		else if (a11 == 4)
			printf("ËÁ");
		else if (a11 == 5)
			printf("Îé");
		else if (a11 == 6)
			printf("Â½");
		else if (a11 == 7)
			printf("Æâ");
		else if (a11 == 8)
			printf("°Æ");
		else if (a11 == 9)
			printf("¾Á");
		printf("½Ç");
	}
	if ((a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) && a11 == 0 && a12 != 0)
		printf("Áã");
	if (a12 != 0) {
		if (a12 == 1)
			printf("Ò¼");
		else if (a12 == 2)
			printf("·¡");
		else if (a12 == 3)
			printf("Èþ");
		else if (a12 == 4)
			printf("ËÁ");
		else if (a12 == 5)
			printf("Îé");
		else if (a12 == 6)
			printf("Â½");
		else if (a12 == 7)
			printf("Æâ");
		else if (a12 == 8)
			printf("°Æ");
		else if (a12 == 9)
			printf("¾Á");
		printf("·Ö");
	}
	if (a12 == 0)
		printf("Õû");
	printf("\n");

	return 0;
}