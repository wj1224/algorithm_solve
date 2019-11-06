#define MAX 100

#include <iostream>
#include <string>

using namespace std;

int T, Testcase, temp;

char map[MAX][MAX];
int N, val, maxValue;

int check(int x, int y, int N, int dir);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> temp;

		for (int i = 0; i < MAX; i++) {

			for (int j = 0; j < MAX; j++) {

				cin >> map[i][j];
				map[i][j] -= '0';

			}

		}

		for (N = 2; N <= MAX; N++) {

			for (int i = 0; i < MAX; i++) {

				for (int j = 0; j + N - 1 < MAX; j++) {

					val = check(i, j, N, 0);
					if (val == 0) {
						maxValue = N;
					}

				}

			}

		}

		for (N = 2; N <= MAX; N++) {

			for (int i = 0; i + N - 1 < MAX; i++) {

				for (int j = 0; j < MAX; j++) {

					val = check(i, j, N, 1);
					if (val == 0 && N > maxValue) {
						maxValue = N;
					}

				}

			}

		}

		cout << "#" << T + 1 << " " << maxValue << endl;

		maxValue = 0;

	}

	return 0;

}

int check(int x, int y, int N, int dir) {

	// dir = 0 : 가로, dir = 1 : 세로

	int cnt = N / 2;
	int check_x1 = x;
	int check_x2 = x + N - 1;
	int check_y1 = y;
	int check_y2 = y + N - 1;
	int value = 0;

	if (dir == 0) {

		while (cnt != 0) {

			if (value != 0)
				break;

			value = map[check_x1][check_y1] - map[check_x1][check_y2];

			check_y1++;
			check_y2--;
			cnt--;

		}

	}

	else if (dir == 1) {

		while (cnt != 0) {

			if (value != 0)
				break;

			value = map[check_x1][check_y1] - map[check_x2][check_y1];

			check_x1++;
			check_x2--;
			cnt--;

		}

	}

	return value;

}