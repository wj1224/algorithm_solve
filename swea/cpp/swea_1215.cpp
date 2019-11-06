#include <iostream>
#include <string>

using namespace std;

int T, Testcase, N;

char map[8][8];
int val, res;

int check(int x, int y, int N, int dir);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {

				cin >> map[i][j];
				map[i][j] -= '0';

			}

		}

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j + N - 1 < 8; j++) {

				val = check(i, j, N, 0);
				if (val == 0)
					res++;

			}

		}

		for (int i = 0; i + N - 1 < 8; i++) {

			for (int j = 0; j < 8; j++) {

				val = check(i, j, N, 1);
				if (val == 0)
					res++;

			}

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

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
	int val = 0;

	if (dir == 0) {

		while (cnt != 0) {

			if (val != 0)
				break;

			val = map[check_x1][check_y1] - map[check_x1][check_y2];

			check_y1++;
			check_y2--;
			cnt--;

		}

	}

	else if (dir == 1) {

		while (cnt != 0) {

			if (val != 0)
				break;

			val = map[check_x1][check_y1] - map[check_x2][check_y1];

			check_x1++;
			check_x2--;
			cnt--;

		}

	}

	return val;

}