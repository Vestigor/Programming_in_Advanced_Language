/* 2353814 马小龙 信05 */
#include <iostream>
using namespace std;

int judge(char *first,char *end)
{
	for (; first < end ; first++, end--) {
		//static int i = 1;
		if (*first != *end){
			//cout << "i=" << i << endl;
			//cout <<"*first="<< * first << " " << "*end=" <<* end << endl;
			return 0;
		}
		//i++;
	}
	return 1;
}

int main()
{
	char str[80], * p;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	cin.get(str, 80, '\n');
	p = str + strlen(str)-1;
	if (judge(str,p))
		cout << "yes" << endl;
	else 
		cout << "no" << endl;

	return 0;
}