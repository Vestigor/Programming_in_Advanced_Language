/* ��05 2353814 ��С�� */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int x;
	
	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if(x < 0 || x > 100)
			continue;
		break;
	}
	
	cout << "cin.good()=" << cin.good() <<  " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}