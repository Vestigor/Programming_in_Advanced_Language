/* 信05 2353814 马小龙 */
#include <iostream>
#include <string>
using namespace std;

int input(string xuehao[], string name[], int i)
{
	int grade;
	cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
	cin >> xuehao[i] >> name[i] >> grade;
	return grade;
}

void output(string xuehao[], string name[], int grade[])
{
	cout << endl;
	cout << "全部学生(学号升序):" << endl;
	for (int i = 0; i < 10; i++)
			cout << name[i] << " " << xuehao[i] << " "  <<grade[i] << endl;
}

void my_rank(string xuehao[], string name[], int grade[])
{
	int i, j, t;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (xuehao[j] > xuehao[j + 1]) {
				xuehao[j].swap(xuehao[j + 1]);
				name[j].swap(name[j + 1]);
				t = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = t;
			}
		}
	}
}

int main()
{
	string xuehao[10], name[10];
	int grade[10], i;
	for (i = 0; i < 10; i++)
		grade[i] = input(xuehao, name, i);
	my_rank(xuehao, name, grade);
	output(xuehao, name, grade);

	return 0;
}