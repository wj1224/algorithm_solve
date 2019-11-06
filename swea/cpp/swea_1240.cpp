#include <iostream>

using namespace std;

int T, Testcase;

int N, M;
char code[5000];
int CodeStart, CodeEnd;
int RealCode[8];
int temp[7];
int res;

void conversion(int idx);
int calc(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> M;

		for (int i = 0; i < N * M; i++) {

			cin >> code[i];
			code[i] -= '0';

		}

		for (int i = 0; i < N * M - 4; i++) {

			if (code[i] == 1 && code[i + 1] == 0 && code[i + 2] == 0 && code[i + 3] == 0 && code[i + 4] == 0) {
				CodeEnd = i;
				break;
			}

		}

		CodeStart = CodeEnd - 55;

		int idx = 0;

		for (int i = CodeStart; i < CodeEnd; i += 7) {

			int j = 0;
			int k = i;

			while (j != 7) {

				temp[j++] = code[k++];

			}

			conversion(idx);
			idx++;

		}

		res = calc();

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i < N * M; i++)
			code[i] = 0;

	}

	return 0;

}

void conversion(int idx) {

	if (temp[0] == 0 && temp[1] == 0 && temp[2] == 0 && temp[3] == 1 && temp[4] == 1 && temp[5] == 0 && temp[6] == 1) // '0'
		RealCode[idx] = 0;
	else if (temp[0] == 0 && temp[1] == 0 && temp[2] == 1 && temp[3] == 1 && temp[4] == 0 && temp[5] == 0 && temp[6] == 1) // '1'
		RealCode[idx] = 1;
	else if (temp[0] == 0 && temp[1] == 0 && temp[2] == 1 && temp[3] == 0 && temp[4] == 0 && temp[5] == 1 && temp[6] == 1) // '2'
		RealCode[idx] = 2;
	else if (temp[0] == 0 && temp[1] == 1 && temp[2] == 1 && temp[3] == 1 && temp[4] == 1 && temp[5] == 0 && temp[6] == 1) // '3'
		RealCode[idx] = 3;
	else if (temp[0] == 0 && temp[1] == 1 && temp[2] == 0 && temp[3] == 0 && temp[4] == 0 && temp[5] == 1 && temp[6] == 1) // '4'
		RealCode[idx] = 4;
	else if (temp[0] == 0 && temp[1] == 1 && temp[2] == 1 && temp[3] == 0 && temp[4] == 0 && temp[5] == 0 && temp[6] == 1) // '5'
		RealCode[idx] = 5;
	else if (temp[0] == 0 && temp[1] == 1 && temp[2] == 0 && temp[3] == 1 && temp[4] == 1 && temp[5] == 1 && temp[6] == 1) // '6'
		RealCode[idx] = 6;
	else if (temp[0] == 0 && temp[1] == 1 && temp[2] == 1 && temp[3] == 1 && temp[4] == 0 && temp[5] == 1 && temp[6] == 1) // '7'
		RealCode[idx] = 7;
	else if (temp[0] == 0 && temp[1] == 1 && temp[2] == 1 && temp[3] == 0 && temp[4] == 1 && temp[5] == 1 && temp[6] == 1) // '8'
		RealCode[idx] = 8;
	else if (temp[0] == 0 && temp[1] == 0 && temp[2] == 0 && temp[3] == 1 && temp[4] == 0 && temp[5] == 1 && temp[6] == 1) // '9'
		RealCode[idx] = 9;

}

int calc(void) {

	int val = (RealCode[0] + RealCode[2] + RealCode[4] + RealCode[6]) * 3 + RealCode[1] + RealCode[3] + RealCode[5] + RealCode[7];

	if (val % 10 == 0)
		return (RealCode[0] + RealCode[1] + RealCode[2] + RealCode[3] + RealCode[4] + RealCode[5] + RealCode[6] + RealCode[7]);

	else
		return 0;
