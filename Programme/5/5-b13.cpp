/* 2353814 马小龙 信05 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;


int main()
{
    #define ABSCISSA 26
    #define ORDINATE 10
    int X, Y;
    char sum;
    char mine[ORDINATE][ABSCISSA] = { 0 };
    srand(int(time(NULL)));//为得到不同的随机数列，初始化随机数种子
    for (int i = 1; i <= 50; i++) {
        while (1) {
            Y = (rand() % ORDINATE) + 0;//随机得到地雷的Y坐标[0-9]
            X = (rand() % ABSCISSA) + 0;//随机得到地雷的X坐标[0-25]
            if (mine[Y][X] != '*')
                break;
        }
        mine[Y][X] = '*';
    }//随机产生50个地雷
    for (int i = 0; i < ORDINATE; i++) {
        for (int j = 0; j < ABSCISSA; j++) {
            if (mine[i][j] != '*') {
                sum = 0;
                if (i != 0) {
                    if (mine[i - 1][j] == '*')
                        sum++;
                }
                if (i != ORDINATE - 1) {
                    if (mine[i + 1][j] == '*')
                        sum++;
                }
                if (j != 0) {
                    if (mine[i][j-1] == '*')
                        sum++;
                }
                if (j != ABSCISSA - 1) {
                    if (mine[i][j+1] == '*')
                        sum++;
                }
                if (i != 0 && j != 0) {
                    if (mine[i - 1][j-1] == '*')
                        sum++;
                }
                if (i != 0 && j != ABSCISSA - 1) {
                    if (mine[i - 1][j+1] == '*')
                        sum++;
                }
                if (i != ORDINATE - 1 && j != 0) {
                    if (mine[i + 1][j-1] == '*')
                        sum++;
                }
                if (i != ORDINATE - 1 && j != ABSCISSA - 1) {
                    if (mine[i + 1][j+1] == '*')
                        sum++;
                }
                mine[i][j] = sum+ '0';
            }
        }    
    }
    for (int i = 0; i < ORDINATE; i++) {
        for (int j = 0; j < ABSCISSA; j++) {
            cout << mine[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}