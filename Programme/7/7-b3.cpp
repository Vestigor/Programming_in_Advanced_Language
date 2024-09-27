/* 2353814 ��С�� ��05 */
#include <iostream>
using namespace std;

/* 1�������������κ����͵�ȫ�ֱ������������������궨���
   2�������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬�������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ����������壩 */

public:
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ����������� */
	Days(int nian, int yue, int ri) {
		year = nian;
		month = yue;
		day = ri;
	}
};

/* --- �˴��������Ա����������ʵ�� --- */
int Days::calc_days()
{
	int month_day[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 },n=0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		month_day[1] = 29;
	else
		month_day[1] = 28;
	if (month < 1 || month>12)
		return -1;
	if(day>month_day[month-1]|| day<0)
		return -1;
	for (int i = 0; i < month - 1; i++)
		n += month_day[i];
	n += day;
	return n;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}