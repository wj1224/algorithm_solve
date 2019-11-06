#include <iostream>

using namespace std;

int T, Testcase;

int button[10];
int X;
int number[1000000];
int res;

void MakeNum(int num, int cnt);
int calc(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		for (int i = 0; i < 10; i++)
			cin >> button[i];
		cin >> X;

		if (X == 1 && button[1] == 1)
			res = 2;

		else {
			MakeNum(0, 0);
			res = calc();
		}

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i < 1000000; i++)
			number[i] = 0;

	}

	return 0;

}

void MakeNum(int num, int cnt) {

	if (num > X)
		return;

	if (cnt == 8)
		return;

	number[num] = cnt;

	for (int i = 0; i < 10; i++) {

		if (button[i] == 1) {

			MakeNum(num * 10 + i, cnt + 1);

		}

	}

}

int calc(void) {

	int target = X;
	int val = 0;
	int i = X;

	while (i != 1) {

		if (number[i] != 0) {

			if (target % i == 0) {

				target /= i;
				val += (number[i] + 1);

				if (target == 1)
					return val;

				i = target + 1;

			}

		}

		i--;

	}

	return -1;

}