/*2353814 ��05 ��С��*/
#include <iostream>
using namespace std;

int main()
{
	cout << "�������꣬�£���" << endl;
	int y, m, d, n;
	cin >> y >> m >> d;
	if (m >= 1 && m <= 12) {
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
			if(m==1){
				if (d >= 1 && d <= 31) {
					n = d;
					cout<<y<<"-"<<m<<"-"<<d<< "��" << y << "��ĵ�" << n<< "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if(m==2){
				if (d >= 1 && d <= 29) {
					n = 31+d;
					cout<<y<<"-"<<m<<"-"<<d<< "��" << y << "��ĵ�" << n<< "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 3) {
				if (d >= 1 && d <= 31) {
					n = 31+29+d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 4) {
				if (d >= 1 && d <= 30) {
					n = 31+29+31+d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 5) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 6) {
				if (d >= 1 && d <= 30) {
					n =31+29+31+30+31+ d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 7) {
				if (d >= 1 && d <= 31) {
					n = 31+29+31+30+31+30+d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 8) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31+d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 9) {
				if (d >= 1 && d <= 30) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31+d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 10) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 +30+ d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 11) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 +31+ d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 12) {
				if (d >= 1 && d <= 31) {
					n = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 +30+ d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}

		}
		else {
			if (m == 1) {
				if (d >= 1 && d <= 31) {
					n = d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 2) {
				if (d >= 1 && d <= 28) {
					n = 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 3) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 4) {
				if (d >= 1 && d <= 30) {
					n = 31 + 28 + 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 5) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 6) {
				if (d >= 1 && d <= 30) {
					n = 31 + 28 + 31 + 30 + 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 7) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 8) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 9) {
				if (d >= 1 && d <= 30) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 10) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 11) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			if (m == 12) {
				if (d >= 1 && d <= 31) {
					n = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << n << "��" << endl;
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}

		}

	}
	else 
		cout << "�������-�·ݲ���ȷ" << endl;
	
		return 0;
}