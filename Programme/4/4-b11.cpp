/* 2353814 信05 马小龙 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
        允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
                 2、定义符号常量
                 3、定义const型变量

        不允许 ：1、定义全局变量
                 2、除print_tower之外的其他函数中不允许定义静态局部变量 
   ----------------------------------------------------------------------------------- */
void print_left(char left)
{
	cout << left;
	if (left == 'A')
		return;
	else
		print_left(left - 1);
}
void print_right(char right, char end)
{
	cout << right;
	if (right == end)
		return;
	else
		print_right(right + 1, end);
}
/***************************************************************************
  函数名称：
  功    能：打印字母塔
  输入参数：
  返 回 值：
  说    明：形参按需设置
            提示：有一个参数order，指定正序/倒序 
***************************************************************************/
void print_tower(char start_ch,char end_ch,int order1,int order2,int width)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
	if (order1 == 0) {
		cout << setfill(' ');
		cout << setw(width) << start_ch;
		if (start_ch != 'A') {
			print_left(start_ch-1);
			print_right('B', start_ch);
			cout << endl;
			if (start_ch == end_ch)
				return;
			else
				print_tower(start_ch + 1, end_ch, order1, order2,width-1);
		}
		else {
			cout << endl;
			if (end_ch != 'A')
				print_tower(start_ch + 1, end_ch, order1, order2, width - 1);
			else
				return;
		}
	}
	else {
		if (order2 == 1) {
			if (end_ch == 'A') 
				return;
			else
			    print_tower(start_ch, end_ch - 1, 1, 0, width + 1);
		}
		else {
			cout << setfill(' ');
			cout << setw(width) << end_ch;
			if (end_ch != start_ch) {
				print_left(end_ch - 1);
				print_right('B', end_ch);
				cout << endl;
				if (end_ch == start_ch)
					return;
				else
					print_tower(start_ch, end_ch - 1, 1, 0, width + 1);
			}
			else {
				cout << endl;
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A',end_ch, 0, 0, end_ch - 'A' + 1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A',end_ch, 1, 0,1); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大宽度输出= */
	print_tower('A',end_ch, 0, 0, end_ch - 'A' + 1);   //打印 A~结束字符的正三角 
	print_tower('A',end_ch, 1, 1,1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
