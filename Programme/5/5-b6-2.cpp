/* 2353814 马小龙 信05 */
#include <iostream>
#include <iomanip>
using namespace std;

int top[3] = { 0 }, zhu_pan[3][10] = { 0 }, num = 1;

void hanoi(int n, char src, char tmp, char dst)
{
    int pan=0, i;
    if (n == 1) {
        cout << "第" << setw(4) << num << " 步(" << setw(2) << n << "): " << src << "-->" << dst;;
        num++;
        if (src == 65) {
            pan = zhu_pan[0][top[0] - 1];
            zhu_pan[0][top[0] - 1] = 0;
            top[0] = top[0] - 1;
        }
        else if (src == 66) {
            pan = zhu_pan[1][top[1] - 1];
            zhu_pan[1][top[1] - 1] = 0;
            top[1] = top[1] - 1;
        }
        else {
            pan = zhu_pan[2][top[2] - 1];
            zhu_pan[2][top[2] - 1] = 0;
            top[2] = top[2] - 1;
        }
        if (dst == 65) {
            zhu_pan[0][top[0]] = pan;
            top[0]++;
        }
        else if (dst == 66) {
            zhu_pan[1][top[1]] = pan;
            top[1]++;
        }
        else {
            zhu_pan[2][top[2]] = pan;
            top[2]++;
        }
        cout << " A:";
        for (i = 0; i < 10; i++) {
            if (zhu_pan[0][i] != 0)
                cout << setw(2) << zhu_pan[0][i];
            else
                cout << "  ";

        }
        cout << " B:";
        for (i = 0; i < 10; i++) {
            if (zhu_pan[1][i] != 0)
                cout << setw(2) << zhu_pan[1][i];
            else
                cout << "  ";
        }
        cout << " C:";
        for (i = 0; i < 10; i++) {
            if (zhu_pan[2][i] != 0)
                cout << setw(2) << zhu_pan[2][i];
            else
                cout << "  ";
        }
        cout << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << num << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        num++;
        if (src == 65) {
            pan = zhu_pan[0][top[0] - 1];
            zhu_pan[0][top[0] - 1] = 0;
            top[0] = top[0] - 1;
        }
        else if (src == 66) {
            pan = zhu_pan[1][top[1] - 1];
            zhu_pan[1][top[1] - 1] = 0;
            top[1] = top[1] - 1;
        }
        else {
            pan = zhu_pan[2][top[2] - 1];
            zhu_pan[2][top[2] - 1] = 0;
            top[2] = top[2] - 1;
        }
        if (dst == 65) {
            zhu_pan[0][top[0]] = pan;
            top[0]++;
        }
        else if (dst == 66) {
            zhu_pan[1][top[1]] = pan;
            top[1]++;
        }
        else {
            zhu_pan[2][top[2]] = pan;
            top[2]++;
        }
        cout << " A:";
        for (i = 0; i < 10; i++) {
            if (zhu_pan[0][i] != 0)
                cout << setw(2) << zhu_pan[0][i];
            else
                cout << "  ";

        }
        cout << " B:";
        for (i = 0; i < 10; i++) {
            if (zhu_pan[1][i] != 0)
                cout << setw(2) << zhu_pan[1][i];
            else
                cout << "  ";
        }
        cout << " C:";
        for (i = 0; i < 10; i++) {
            if (zhu_pan[2][i] != 0)
                cout << setw(2) << zhu_pan[2][i];
            else
                cout << "  ";
        }
        cout << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n, j;
    char src, tmp, dst, i;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.fail() || n > 10 || n < 1) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else {
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.fail() || src > 99 || src < 65 || src < 97 && src>67) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else {
            if (src > 96)
                src = src - 32;
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.fail() || dst > 99 || dst < 65 || dst < 97 && dst>67) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else {
            if (dst > 96)
                dst = dst - 32;
            if (src == dst) {
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
                cin.clear();
                cin.ignore(2147483647, '\n');
                continue;
            }
            cin.clear();
            cin.ignore(2147483647, '\n');
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
            zhu_pan[0][i] = n - i;
        else if (src == 66)
            zhu_pan[1][i] = n - i;
        else if (src == 67)
            zhu_pan[2][i] = n - i;
    }
    if (src == 65)
        top[0] = i;
    else if (src == 66)
        top[1] = i;
    else if (src == 67)
        top[2] = i;
    cout << "初始:" << setw(15) << " ";
    cout << " A:";
    for (j = 0; j < 10; j++) {
        if (zhu_pan[0][j] != 0)
            cout << setw(2) << zhu_pan[0][j];
        else
            cout << "  ";

    }
    cout << " B:";
    for (j = 0; j < 10; j++) {
        if (zhu_pan[1][j] != 0)
            cout << setw(2) << zhu_pan[1][j];
        else
            cout << "  ";
    }
    cout << " C:";
    for (j = 0; j < 10; j++) {
        if (zhu_pan[2][j] != 0)
            cout << setw(2) << zhu_pan[2][j];
        else
            cout << "  ";
    }
    cout << endl;
    hanoi(n, src, tmp, dst);
    
    return 0;
}
