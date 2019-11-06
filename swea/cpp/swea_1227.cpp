#include <iostream>
#include <stack>

using namespace std;

int T, Testcase;

int numT;
char map[100][100];
int visit[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
stack<pair<int, int>> s;
int res;

void solve(int x, int y);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> numT;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				visit[i][j] = map[i][j] - '0';
			}
		}

		s.push({ 1, 1 });
		solve(1, 1);

		cout << "#" << T + 1 << " " << res << endl;
		res = 0;
		while (!s.empty())
			s.pop();

	}

	return 0;

}

void solve(int x, int y) {

	int nx = 0;
	int ny = 0;

	while (!s.empty()) {

		for (int i = 0; i < 4; i++) {

			nx = x + dx[i];
			ny = y + dy[i];

			if (visit[nx][ny] == 3) {
				res = 1;
				break;
			}

			else if (visit[nx][ny] == 0) {

				visit[x][y] = 1;
				s.push({ x, y });

				x = nx;
				y = ny;
				break;

			}

			if (i == 3) {

				visit[x][y] = 1;
				x = s.top().first;
				y = s.top().second;
				s.pop();

			}

		}

		if (res == 1)
			break;

	}

}