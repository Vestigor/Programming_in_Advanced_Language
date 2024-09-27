/* 2353814 马小龙 信05 */
/* 2253797 黄艺鑫 2350231 高柏舟 2353113 李阔 2353250 罗力 2353788 潘越 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    #define ABSCISSA 26
    #define ORDINATE 10
    char sum1=0, ret,sum2;
    char mine[ORDINATE][ABSCISSA] = { 0 };
    for (int i = 0; i < ORDINATE; i++) {
        for (int j = 0; j < ABSCISSA; j++) {
            while (1) {
                scanf("%c", &ret);
                if ((ret >= '0' && ret <= '8') || ret == '*') {
                    mine[i][j] = ret;
                    break;
                }
            }
            if (mine[i][j] == '*')
                sum1++;
        }
    }
    if (sum1 != 50) {
        printf("错误1\n");
        return 0;
    }
    for (int i = 0; i < ORDINATE; i++) {
        for (int j = 0; j < ABSCISSA; j++) {
            if (mine[i][j] != '*') {
                sum2 = 0;
                if (i != 0) {
                    if (mine[i - 1][j] == '*')
                        sum2++;
                }
                if (i != ORDINATE - 1) {
                    if (mine[i + 1][j] == '*')
                        sum2++;
                }
                if (j != 0) {
                    if (mine[i][j - 1] == '*')
                        sum2++;
                }
                if (j != ABSCISSA - 1) {
                    if (mine[i][j + 1] == '*')
                        sum2++;
                }
                if (i != 0 && j != 0) {
                    if (mine[i - 1][j - 1] == '*')
                        sum2++;
                }
                if (i != 0 && j != ABSCISSA - 1) {
                    if (mine[i - 1][j + 1] == '*')
                        sum2++;
                }
                if (i != ORDINATE - 1 && j != 0) {
                    if (mine[i + 1][j - 1] == '*')
                        sum2++;
                }
                if (i != ORDINATE - 1 && j != ABSCISSA - 1) {
                    if (mine[i + 1][j + 1] == '*')
                        sum2++;
                }
                if (mine[i][j] != sum2 + '0') {
                    printf("错误2\n");
                    return 0;
                }
            }
        }
    }
    printf("正确\n");

    return 0;
}