/* 2353814 马小龙 信05 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int topA = 0, topB = 0, topC = 0, A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 }, num = 1;

void hanoi(int n, char src, char tmp, char dst)
{
    int pan = 0,i;
    if (n == 1) {
        printf("第%4d 步(%2d): %c-->%c", num, n, src, dst);
        num++;
        if (src == 65) {
            pan = A[topA - 1];
            A[topA - 1] = 0;
            topA = topA - 1;
        }
        else if (src == 66) {
            pan = B[topB - 1];
            B[topB - 1] = 0;
            topB = topB - 1;
        }
        else {
            pan = C[topC - 1];
            C[topC - 1] = 0;
            topC = topC - 1;
        }
        if (dst == 65) {
            A[topA] = pan;
            topA++;
        }
        else if (dst == 66) {
            B[topB] = pan;
            topB++;
        }
        else {
            C[topC] = pan;
            topC++;
        }
        printf(" A:");
        for (i = 0; i < 10; i++) {
            if (A[i] != 0)
                printf("%2d", A[i]);
            else
                printf("  ");

        }
        printf(" B:");
        for (i = 0; i < 10; i++) {
            if (B[i] != 0)
                printf("%2d", B[i]);
            else
                printf("  ");
        }
        printf(" C:");
        for (i = 0; i < 10; i++) {
            if (C[i] != 0)
                printf("%2d", C[i]);
            else
                printf("  ");
        }
        printf("\n");
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", num, n, src, dst);
        num++;
        if (src == 65) {
            pan = A[topA - 1];
            A[topA - 1] = 0;
            topA = topA - 1;
        }
        else if (src == 66) {
            pan = B[topB - 1];
            B[topB - 1] = 0;
            topB = topB - 1;
        }
        else {
            pan = C[topC - 1];
            C[topC - 1] = 0;
            topC = topC - 1;
        }
        if (dst == 65) {
            A[topA] = pan;
            topA++;
        }
        else if (dst == 66) {
            B[topB] = pan;
            topB++;
        }
        else {
            C[topC] = pan;
            topC++;
        }
        printf(" A:");
        for (i = 0; i < 10; i++) {
            if (A[i] != 0)
                printf("%2d", A[i]);
            else
                printf("  ");

        }
        printf(" B:");
        for (i = 0; i < 10; i++) {
            if (B[i] != 0)
                printf("%2d", B[i]);
            else
                printf("  ");
        }
        printf(" C:");
        for (i = 0; i < 10; i++) {
            if (C[i] != 0)
                printf("%2d", C[i]);
            else
                printf("  ");
        }
        printf("\n");
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n, j;
    char src, tmp, dst, i,ret;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret = scanf("%d", &n);
        if (ret!=1 || n > 10 || n < 1) {
            while (getchar() != '\n')
                ;
            continue;
        }
        else {
            while (getchar() != '\n')
                ;
            break;
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        if (ret != 1 || src > 99 || src < 65 || src < 97 && src>67) {
            while (getchar() != '\n')
                ;
            continue;
        }
        else {
            if (src > 96)
                src = src - 32;
            while (getchar() != '\n')
                ;
            break;
        }
    }
    while (1) {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        if (ret != 1 || dst > 99 || dst < 65 || dst < 97 && dst>67) {
            while (getchar() != '\n')
                ;
            continue;
        }
        else {
            if (dst > 96)
                dst = dst - 32;
            if (src == dst) {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
                while (getchar() != '\n')
                    ;
                continue;
            }
            while (getchar() != '\n')
                ;
            break;
        }
    }
    if (src == 65 && dst == 66 || src == 66 && dst == 65)
        tmp = 67;
    else if (src == 65 && dst == 67 || src == 67 && dst == 65)
        tmp = 66;
    else if (src == 66 && dst == 67 || src == 67 && dst == 66)
        tmp = 65;
    for (i = 0; i < n; i++) {
        if (src == 65)
            A[i] = n - i;
        else if (src == 66)
            B[i] = n - i;
        else if (src == 67)
            C[i] = n - i;
    }
    if (src == 65)
        topA = i;
    else if (src == 66)
        topB = i;
    else if (src == 67)
        topC = i;
    printf("初始:               ");
    printf(" A:");
    for (j = 0; j < 10; j++) {
        if (A[j] != 0)
            printf("%2d", A[j]);
        else
            printf("  ");

    }
    printf(" B:");
    for (j = 0; j < 10; j++) {
        if (B[j] != 0)
            printf("%2d", B[j]);
        else
            printf("  ");
    }
    printf(" C:");
    for (j = 0; j < 10; j++) {
        if (C[j] != 0)
            printf("%2d", C[j]);
        else
            printf("  ");
    }
    printf("\n");
    hanoi(n, src, tmp, dst);

    return 0;
}