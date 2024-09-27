/* 2353814 马小龙 信05 */
#include <iostream>
using namespace std;

unsigned int transform(char *start,char *end)
{
	unsigned int n = 0, * pn;
	pn = &n;
	for (; end - start + 1 >= 1; start++) {
		if (*start == '1') {
			unsigned int a = 1;
			unsigned int* pa = &a;
			for (int i = 1; i <= end - start; i++)
				*pa *= 2;
			*pn += *pa;
		}
	}
	return *pn;
}

int main()
{
	char str[33],*p;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin.get(str, 33, '\n');
	p = str + strlen(str) - 1;
    cout << transform(str,p)<<endl;

	return 0;
}