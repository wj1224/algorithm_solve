#include <iostream>
#include <stack>

using namespace std;

int T, Testcase, N;

char map[16][16];
int visit[16][16];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int res;

stack<pair<int, int>> s;

int search(int x, int y);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < 16; i++) {

			for (int j = 0; j < 16; j++) {

				cin >> map[i][j];

				if (map[i][j] == '1')
					visit[i][j] = 1;
				else
					visit[i][j] = 0;

			}

		}

		res = search(1, 1);

		cout << "#" << T + 1 << " " << res << endl;

		while (!s.empty())
			s.pop();


	}

	return 0;

}

int search(int x, int y) {

	int nx = 0;
	int ny = 0;

	s.push({ x, y });
	visit[x][y] = 1;

	while (!s.empty()) {

		if (visit[x][y + 1] == 1 && visit[x][y - 1] == 1 && visit[x + 1][y] == 1 && visit[x - 1][y] == 1) {
			x = s.top().first;
			y = s.top().second;
			s.pop();
		}

		else {

			for (int i = 0; i < 4; i++) {

				nx = x + dx[i];
				ny = y + dy[i];

				if (map[nx][ny] == '0' && visit[nx][ny] == 0) {

					x = nx;
					y = ny;
					visit[x][y] = 1;
					s.push({ x, y });
					break;

				}

				else if (map[nx][ny] == '3')
					return 1;

			}

		}

	}

	return 0;

}