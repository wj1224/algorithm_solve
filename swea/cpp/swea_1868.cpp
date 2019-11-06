#include <iostream>

using namespace std;

int T, Testcase, N;

int map[300][300];
char map2[300][300];
int visit[300][300];

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int res;

void map_check(void);
void dfs(int x, int y);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				cin >> map2[i][j];
				if (map2[i][j] == '*')
					map[i][j] = 9999;

			}

		}

		map_check();

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				if (map[i][j] == 0 && visit[i][j] == 0) {
					visit[i][j] = 1;
					dfs(i, j);
					res++;
				}
			}

		}

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				if (map[i][j] != 9999 && map[i][j] != 0 && visit[i][j] == 0)
					res++;

			}

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				map[i][j] = 0;
				map2[i][j] = 0;
				visit[i][j] = 0;

			}

		}

	}

	return 0;

}


void map_check(void) {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (map2[i][j] == '*') {

				for (int k = 0; k < 8; k++) {

					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map2[nx][ny] != '*') {

						map[nx][ny]++;

					}

				}

			}

		}

	}

}

void dfs(int x, int y) {

	if (map[x][y] == 9999)
		return;

	else if (map[x][y] != 0 && map[x][y] != 9999) {
		visit[x][y] = 1;
		return;
	}

	else {

		visit[x][y] = 1;

		for (int i = 0; i < 8; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == 0) {

				dfs(nx, ny);

			}

		}

	}

}