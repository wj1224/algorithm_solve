#include <iostream>

using namespace std;

int T, Testcase, N;

int map[100][100];
int visit[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int minValue = 9999999;
int minIdx;

void main_func(int x, int y, int length, int idx);

int main() {

	Testcase = 10;
	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < 100; i++) {

			for (int j = 0; j < 100; j++) {

				cin >> map[i][j];

			}

		}

		for (int i = 0; i < 100; i++) {

			if (map[0][i] == 1)
				main_func(0, i, 0, i);

			for (int i = 0; i < 100; i++) {

				for (int j = 0; j < 100; j++) {

					visit[i][j] = 0;

				}

			}

		}

		cout << "#" << T + 1 << " " << minIdx << endl;

		minValue = 9999999;

	}

	return 0;

}

void main_func(int x, int y, int length, int idx) {

	while (x < 99) {

		if (y + dy[1] <= 99 && map[x][y + dy[1]] == 1 && visit[x][y + dy[1]] == 0) {
			y = y + dy[1];
			length++;
			visit[x][y] = 1;
		}
		else if (y + dy[0] >= 0 && map[x][y + dy[0]] == 1 && visit[x][y + dy[0]] == 0) {
			y = y + dy[0];
			length++;
			visit[x][y] = 1;
		}
		else if (map[x + dx[3]][y] == 1 && visit[x + dx[3]][y] == 0) {
			x = x + dx[3];
			length++;
			visit[x][y] = 1;
		}
	}

	if (x == 99) {

		if (length <= minValue) {
			minValue = length;
			minIdx = idx;
		}

	}

	return;

}