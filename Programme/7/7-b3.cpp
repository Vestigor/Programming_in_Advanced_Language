/* 2353814 马小龙 信05 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */

public:
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int nian, int yue, int ri) {
		year = nian;
		month = yue;
		day = ri;
	}
};

/* --- 此处给出类成员函数的体外实现 --- */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
