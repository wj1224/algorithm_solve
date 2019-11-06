#include <iostream>

using namespace std;

int T, Testcase, temp;

int map[100][100];
int visit[100][100];
int res = -1;
int dx[3] = { 0, 0, 1 };
int dy[3] = { 1, -1, 0 };

void ladder(int idx, int x, int y);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> temp;

		for (int i = 0; i < 100; i++) {

			for (int j = 0; j < 100; j++) {

				cin >> map[i][j];

			}

		}

		for (int k = 0; k < 100; k++) {

			if (map[0][k] == 1) {

				ladder(k, 0, k);

				if (res != -1)
					break;

			}

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = -1;

	}

	return 0;

}

void ladder(int idx, int x, int y) {

	if (map[x][y] == 2) {

		res = idx;

		return;

	}

	else if (x == 99)
		return;

	else {

		for (int i = 0; i < 3; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((x != nx && nx >= 0 && nx <= 99) || (y != ny && ny >= 0 && ny <= 99)) {

				if (visit[nx][ny] == 0 && (map[nx][ny] == 1 || map[nx][ny] == 2)) {

					visit[nx][ny] = 1;
					ladder(idx, nx, ny);
					visit[nx][ny] = 0;
					return;

				}

			}



		}

	}

}