/* 2353814 ÂíĞ¡Áú ĞÅ05 */
#include <iostream>
using namespace std;

int main()
{
	int light[100], i, j, k;
	for (k = 0; k < 100; k++)
		light[k] = 0;
	for (i = 1; i <= 100; i++) {
		for (j = 0; j < 100; j++) {
			if ((j + 1) % i == 0) {
				if (light[j] == 0)
					light[j] = 1;
				else
					light[j] = 0;
			}
		}
	}
	for (k = 0; k < 100; k++) {
		if (light[k] == 1) {
			cout << k + 1;
			if (k != 99)
				cout << ' ';
		}
	}
	cout << endl;

	return 0;
}