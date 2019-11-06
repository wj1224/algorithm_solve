#include <iostream>

using namespace std;

int Testcase;

int num, cnt;

int numarr[6];

int res, maxValue;

int Dig;

int convert(int ori);
int calc(void);
void dfs(int idx, int res);

int main(void) {

	cin >> Testcase;

	for (int T = 0; T < Testcase; T++) {

		cin >> num >> cnt;

		maxValue = num;
		Dig = convert(num);

		dfs(0, 0);

		cout << "#" << T + 1 << " " << maxValue << endl;

		fill(&numarr[0], &numarr[6], 0);

	}

	return 0;

}

void dfs(int idx, int res) {

	int temp = 0;
	int temp2 = 0;

	if (idx == cnt) {

		res = calc();

		if (res >= maxValue) {

			maxValue = res;

		}

		return;

	}

	else {

		for (int i = 0; i < Dig - 1; i++) {

			temp2 = 0;

			for (int j = i + 1; j < Dig; j++) {

				if (numarr[j] > temp2) {

					temp2 = numarr[j];

				}

			}

			for (int j = i; j < Dig; j++) {

				if ((numarr[i] < numarr[j]) && (numarr[j] == temp2)) {

					temp = numarr[i];
					numarr[i] = numarr[j];
					numarr[j] = temp;

					dfs(idx + 1, res);

					temp = numarr[j];
					numarr[j] = numarr[i];
					numarr[i] = temp;

				}

			}

		}

	}

}

int convert(int ori) {

	int temp = ori, temp2 = ori;
	int j = 0;
	int Digit = 0;
	int fact = 1;

	while (temp) {

		temp /= 10;
		Digit++;

	}

	for (int i = Digit - 1; i >= 0; i--) {

		for (int k = i - 1; k >= 0; k--)
			fact *= 10;

		numarr[j++] = temp2 / fact;
		temp2 = temp2 % fact;

		fact = 1;
	}

	return Digit;

}

int calc(void) {

	int fact = 1;
	int sum = 0;

	for (int l = 0; l < Dig - 1; l++)
		fact *= 10;

	for (int l = 0; l < Dig; l++) {

		sum += (numarr[l] * fact);
		fact /= 10;

	}

	return sum;

}