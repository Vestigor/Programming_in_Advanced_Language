/* 2353814 马小龙 信05 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

#define N_POW	112		//幂的次数
#define N_NUM	N_POW+1	//十进制形式的小数位数

/***************************************************************************
  函数名称：
  功    能：输出某一行的幂次（某个一维数组的内容）
  输入参数：
  返 回 值：
  说    明：pormpt为非空串则输出串内容
                  为空串则输出“2^-xxx”，具体见demo
***************************************************************************/
void output(const char prompt[], const char d[])
{
	int i;
	cout << prompt;
	for (i = N_NUM; i >= 1; i--) {
		if (d[i] != 0)
			break;
	}
	for (int j = 0; j <= i; j++) {
		if (j == 0 && strlen(prompt) == 2) {
			cout << setw(4) << -i << " : 0.";
		}
		else if (j >= 1)
			cout << int(d[j]);
	}
	cout << endl;

}

/***************************************************************************
  函数名称：
  功    能：用二维数组第i行的值，计算第i+1行
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void calc_next(char d_cur[], char d_next[])
{
	char a=0;
	int i;
	for (i = 1; i <= N_NUM; i++) {
		d_next[i] = (a + d_cur[i]) / 2;
		if (d_cur[i] % 2 == 0)
			a = 0;
		else
			a = 10;
	}
}

/***************************************************************************
  函数名称：
  功    能：根据幂次表，计算某个二进制小数的十进制值
  输入参数：char pure_decimal[] : 存放二进制小数的数组
            char out[] ：存放计算得到的十进制小数
		   char power_table[][N_NUM + 1]：幂次表
  返 回 值：
  说    明：
 ***************************************************************************/
void calc_num(char pure_decimal[], char out[], char power_table[][N_NUM + 1])
{
	int i,j;
	for (i = N_POW; i >=1; i--) {
		if (pure_decimal[i] == 1) {
			for (j = N_NUM; j >= 1; j--) {
				out[j] = out[j] + power_table[i][j];
				if (out[j] >= 10) {
					out[j] = out[j] - 10;
					out[j-1] = out[j-1]+1;
				}
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：输入一个二进制纯小数
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
void input_pure_decimal(char pure_decimal[])
{
	int i, j, k, sum1, sum2;
	char yanzhen;
	cout << "请输入一个二进制纯小数，小数点开头，小数点后不超过112位(例：.101101)" << endl;
	while (1) {
		for (int z = 0; z <= N_NUM; z++)
			pure_decimal[z] = 0;
		i = 0;
		sum1 = 0;
		sum2 = 0;
		while (i <= N_POW+1) {
			if (i <= N_POW) {
				pure_decimal[i] = getchar();
				if (pure_decimal[i] == '\n')
					break;
			}
			else {
				yanzhen = getchar();
				if (yanzhen != '\n') {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
					break;
			}
			i++;
		}
		if (pure_decimal[0] != '.') {
			cout << "不是以.开头，请重输" << endl;
			continue;
		}
		if (pure_decimal[1] == '\n') {
			cout << "输入数据为空，请重输" << endl;
			continue;
		}
		for (k = 1; k <= N_NUM; k++) {
			if (pure_decimal[k] != '1' && pure_decimal[k] != '0' && pure_decimal[k] != '\n'&& pure_decimal[k] != 0)
				sum1++;
		}
		if (sum1 != 0) {
			cout << "输入的不是0/1，请重输" << endl;
			continue;
		}
		for (j = 1; j <= N_NUM; j++) {
			if (pure_decimal[j] == '1')
			    sum2++;
		}
		if (sum2 == 0) {
			cout << "输入为全0，请重输" << endl;
			continue;
		}
		break;
	}
	cout << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：is_upper ：1 - 上标尺
						 0 - 下标尺
  返 回 值：
  说    明：
***************************************************************************/
void output_rod(const bool is_upper)
{
	if (is_upper) { //上标尺
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------- 上标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else {//下标尺
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "----------- 下标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 说明：首先定义 power_table[113][114]，输出为全0，再进行初始化
	* 
	*  1、第[0]行整个不用，[1]~[112] 与2^-1 ~ 2^-112 对应，因此需要113行
	*  2、第[0]列存放幂次，[1]~[112]列依次存放十分位、百分位、千分位、...  （2^-i次方的十进制小数，最多i位），[113]预留，用于某些特殊要求，比如\0
	*  2、每行的第0列存放幂次，[1]~开始存放十进制的每一位，从而达到高精度存放的目的
	*     例：        第[0]列  第[1]列  第[2]列  第[3]列  第[4]列 ...
	*		第[1]行   -1     5        0        0        0		//表示0.5
	*		第[2]行   -2     2        5        0        0		//表示0.25
	*		第[3]行   -3     1        2        5        0		//表示0.125
	*		第[4]行   -4     0        6        2        5		//表示0.0625
	*			...
	*		第[112]行 -112   ...
	*
	注：1、本二维数组的类型，既可以是int，也可以是char，因为计算时，每个元素的值都在0-9之间，用char足够了（char型输出时注意数字0-9和字符0-9的问题即可）
	    2、因为如此，本题放在数组综合训练中，而没有放在字符数组中
	*/
	char power_table[N_POW + 1][N_NUM + 1] = { 0 }; //先全部初始化为0
	int i;

	/* 初始化，[0]里面存放幂次，初始化后的结果为：
	   行|列  [0]   [1]   [2]
	   [0]     0     0     0  //本行不用
	   [1]     -1    5     0  // 2^-1 初始化为0.5
	   [2]     -2    0     0
	   ...
	   [112]   -112  0     0
	*/
	for (i = 1; i <= N_POW; i++) {
		power_table[i][0] = -i; //幂次 -1 ~ -52
	}
	power_table[1][1] = 5; // 2^-1 = 0.5，先置[1][1]为5

	/* 循环方式计算幂表：
	   1、二维数组带一个下标，表示一个大小为114的一维数组
	   2、2^-1为已知的0.5，power_table[1]的内容为 -1 5 0 0 0 ... 0
	*/
	for (i = 1; i < N_POW; i++)
		calc_next(power_table[i], power_table[i+1]); //已知2^-i，求2^-(i+1)

	/* 上标尺 */
	output_rod(1);

	/* 输出 */
	for (i = 1; i <= N_POW; i++)
		output("2^", power_table[i]);

	/* 下标尺 */
	output_rod(0);
	cout << endl;

	/* 输入一个二进制纯小数 */
	char pure_decimal[N_NUM + 1] = { 0 };
	input_pure_decimal(pure_decimal);
	for (int k = 1; k <= N_NUM; k++) {
		if (pure_decimal[k] == '1')
			pure_decimal[k] = 1;
		else
			pure_decimal[k] = 0;
	}	

	/* 上标尺 */
	output_rod(1);

	output("输入数据 : ", pure_decimal); 
	char out[N_NUM + 1] = { 0 };
	calc_num(pure_decimal, out, power_table);
	output("计算值 : 0.", out);
	/* 下标尺 */
	output_rod(0);

	cout << endl;

	return 0;
}

/*
PPT例题的测试数据
.00110011001100110011010
*/
