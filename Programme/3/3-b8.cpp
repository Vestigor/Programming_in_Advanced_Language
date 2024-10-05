/*2353814 信05 马小龙*/
#include <iostream>
#include <iomanip>
#include <cmath>      
using namespace std;

int main()
{
	int x ;
    double a = 0, t = 1, m = 1, b = 1, n = 1;
    while (1) {
        cout << "请输入x的值[-10 ~ +65]" << endl;
        cin >> x;
        if (x < -10 || x > 65) {
            cout << "输入非法，请重新输入" << endl;
            continue;
        }
        break;
    }
    while (fabs(t) > 1e-6) {
        a = a + t;
        t = t * (x / n);
        n++;
    }
    cout << "e^" << x << "="<< setprecision(10) << a << endl;

    return 0;
}