/* 2353814 马小龙 信05 */
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	double n;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen, a;
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> n;
		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (n < 0 || n >= 10000000000)
			continue;
		break;
	}
	shiyi = int(n / 10) / 100000000;
	yi = int(n / 10) % 100000000 / 10000000;
	qianwan = int(n / 10) % 10000000 / 1000000;
	baiwan = int(n / 10) % 1000000 / 100000;
	shiwan = int(n / 10) % 100000 / 10000;
	wan = int(n / 10) % 10000 / 1000;
	qian = int(n / 10) % 1000 / 100;
	bai = int(n / 10) % 100 / 10;
	shi = int(n / 10) % 10;
	yuan = int(floor((n / 10 - floor(n / 10)) * 10));
	jiao = int(round((n - floor(n)) * 100)) / 10;
	fen = int(round((n - floor(n)) * 100)) % 10;
	cout << "大写结果是:" << endl;
	daxie(shiyi, 0);
	if (shiyi != 0) {
		cout << "拾";
		if (yi == 0)
			cout << "亿";
	}
	daxie(yi, 0);
	if (yi != 0)
		cout << "亿";
	if ((shiyi != 0 || yi != 0) && baiwan != 0)
		a = 1;
	else
		a = 0;
	daxie(qianwan, a);
	if (qianwan != 0) {
		cout << "仟";
		if (baiwan == 0 && shiwan == 0 && wan == 0)
			cout << "万";
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0) && shiwan != 0)
		a = 1;
	else
		a = 0;
	daxie(baiwan, a);
	if (baiwan != 0) {
		cout << "佰";
		if (shiwan == 0 && wan == 0)
			cout << "万";
	}
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0) && wan != 0)
		a = 1;
	else
		a = 0;
	daxie(shiwan, a);
	if (shiwan != 0) {
		cout << "拾";
		if (wan == 0)
			cout << "万";
	}
	daxie(wan, 0);
	if (wan != 0) 
		cout << "万";
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) && bai != 0)
		a = 1;
	else
		a = 0;
	daxie(qian, a);
	if (qian != 0) 
		cout << "仟";
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0) && shi != 0)
		a = 1;
	else
		a = 0;
	daxie(bai, a);
	if (bai != 0)
		cout << "佰";
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0) && yuan != 0)
		a = 1;
	else
		a = 0;
	daxie(shi, a);
	if (shi != 0)
		cout << "拾";
	daxie(yuan, 0);
	if (n == 0) {
		daxie(0, 1);
		cout << "圆";
	}
	if (int(n) != 0)
		cout << "圆";
	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0) && fen != 0)
		a = 1;
	else
		a = 0;
	daxie(jiao, a);
	if (jiao != 0)
		cout << "角";
	daxie(fen, 0);
	if (fen != 0)
		cout << "分";
	else
		cout << "整";
	cout << endl;
	return 0;
}
