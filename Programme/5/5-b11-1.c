/* 信05 2353814 马小龙 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
int ling()
{
	int i;
	for (i = 0; i < 256; i++) {
		if (result[i] == 0)
			break;
	}
	return i;
}
void daxie(int num, int flag_of_zero)
{
	int mowei;
	switch (num) {
		case 0:
			if (flag_of_zero) {
				mowei = ling();
				result[mowei] = chnstr[0];
				result[mowei + 1] = chnstr[1];
			}
			break;
		case 1:
			mowei = ling();
			result[mowei] = chnstr[2];
			result[mowei + 1] = chnstr[3];
			break;
		case 2:
			mowei = ling();
			result[mowei] = chnstr[4];
			result[mowei + 1] = chnstr[5];
			break;
		case 3:
			mowei = ling();
			result[mowei] = chnstr[6];
			result[mowei + 1] = chnstr[7];
			break;
		case 4:
			mowei = ling();
			result[mowei] = chnstr[8];
			result[mowei + 1] = chnstr[9];
			break;
		case 5:
			mowei = ling();
			result[mowei] = chnstr[10];
			result[mowei + 1] = chnstr[11];
			break;
		case 6:
			mowei = ling();
			result[mowei] = chnstr[12];
			result[mowei + 1] = chnstr[13];
			break;
		case 7:
			mowei = ling();
			result[mowei] = chnstr[14];
			result[mowei + 1] = chnstr[15];
			break;
		case 8:
			mowei = ling();
			result[mowei] = chnstr[16];
			result[mowei + 1] = chnstr[17];
			break;
		case 9:
			mowei = ling();
			result[mowei] = chnstr[18];
			result[mowei + 1] = chnstr[19];
			break;
		default:
			printf( "error");
			break;
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
    /* --允许添加需要的内容 --*/
	double n;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen, a;
	const char unit[] = "亿万仟佰拾圆角分整";
	int ret,mowei;
	while (1) {
		printf("请输入[0-100亿)之间的数字:\n");
		ret = scanf("%lf", &n);
		if (ret != 1) {
			while (getchar() != '\n')
				;
			continue;
		}
		if (n < 0 || n >= 10000000000)
			continue;
		break;
	}
	shiyi = (int)(n / 10) / 100000000;
	yi = (int)(n / 10) % 100000000 / 10000000;
	qianwan = (int)(n / 10) % 10000000 / 1000000;
	baiwan = (int)(n / 10) % 1000000 / 100000;
	shiwan = (int)(n / 10) % 100000 / 10000;
	wan = (int)(n / 10) % 10000 / 1000;
	qian = (int)(n / 10) % 1000 / 100;
	bai = (int)(n / 10) % 100 / 10;
	shi = (int)(n / 10) % 10;
	yuan = (int)(floor((n / 10 - floor(n / 10)) * 10));
	jiao = (int)(round((n - floor(n)) * 100)) / 10;
	fen = (int)(round((n - floor(n)) * 100)) % 10;
	daxie(shiyi, 0);
	if (shiyi != 0) {
		mowei = ling();
		result[mowei] = unit[8];
		result[mowei+1] = unit[9];
		if (yi == 0) {
			mowei = ling();
			result[mowei] = unit[0];
			result[mowei+1] = unit[1];
		}
	}
	daxie(yi, 0);
	if (yi != 0) {
		mowei = ling();
		result[mowei] = unit[0];
		result[mowei+1] = unit[1];
	}
	if ((shiyi != 0 || yi != 0) && baiwan != 0)
		a = 1;
	else
		a = 0;
	daxie(qianwan, a);
	if (qianwan != 0) {
		mowei = ling();
		result[mowei] = unit[4];
		result[mowei+1] = unit[5];
		if (baiwan == 0 && shiwan == 0 && wan == 0) {
			mowei = ling();
			result[mowei] = unit[2];
			result[mowei + 1] = unit[3];
		}
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0) && shiwan != 0)
		a = 1;
	else
		a = 0;
	daxie(baiwan, a);
	if (baiwan != 0) {
		mowei = ling();
		result[mowei] = unit[6];
		result[mowei + 1] = unit[7];
		if (shiwan == 0 && wan == 0) {
			mowei = ling();
			result[mowei] = unit[2];
			result[mowei + 1] = unit[3];
		}
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0) && wan != 0)
		a = 1;
	else
		a = 0;
	daxie(shiwan, a);
	if (shiwan != 0) {
		mowei = ling();
		result[mowei] = unit[8];
		result[mowei + 1] = unit[9];
		if (wan == 0) {
			mowei = ling();
			result[mowei] = unit[2];
			result[mowei + 1] = unit[3];
		}
	}
	daxie(wan, 0);
	if (wan != 0) {
		mowei = ling();
		result[mowei] = unit[2];
		result[mowei + 1] = unit[3];
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) && bai != 0)
		a = 1;
	else
		a = 0;
	daxie(qian, a);
	if (qian != 0) {
		mowei = ling();
		result[mowei] = unit[4];
		result[mowei + 1] = unit[5];
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0) && shi != 0)
		a = 1;
	else
		a = 0;
	daxie(bai, a);
	if (bai != 0) {
		mowei = ling();
		result[mowei] = unit[6];
		result[mowei + 1] = unit[7];
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0) && yuan != 0)
		a = 1;
	else
		a = 0;
	daxie(shi, a);
	if (shi != 0) {
		mowei = ling();
		result[mowei] = unit[8];
		result[mowei + 1] = unit[9];
	}
	daxie(yuan, 0);
	if (n == 0) {
		daxie(0, 1);
		mowei = ling();
		result[mowei] = unit[10];
		result[mowei + 1] = unit[11];
	}
	if ((int)n != 0) {
		mowei = ling();
		result[mowei] = unit[10];
		result[mowei + 1] = unit[11];
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0) && fen != 0)
		a = 1;
	else
		a = 0;
	daxie(jiao, a);
	if (jiao != 0) {
		mowei = ling();
		result[mowei] = unit[12];
		result[mowei + 1] = unit[13];
	}
	daxie(fen, 0);
	if (fen != 0) {
		mowei = ling();
		result[mowei] = unit[14];
		result[mowei + 1] = unit[15];
	}
	else {
		mowei = ling();
		result[mowei] = unit[16];
		result[mowei + 1] = unit[17];
	}
	printf("大写结果是:\n");

    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
