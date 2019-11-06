#include <iostream>
#include <queue>

using namespace std;

int T, Testcase, N;

char map[100][100];
int dist[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int res;

priority_queue<pair<int, pair<int, int>>> q;

int dijkstra(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				map[i][j] -= '0';
				dist[i][j] = 100000000;
			}
		}

		res = dijkstra();

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				dist[i][j] = 100000000;
			}
		}

	}

	return 0;

}

int dijkstra(void) {

	int cost = 0, x = 0, y = 0;

	dist[0][0] = 0;

	q.push({ -dist[0][0],{ 0, 0 } });

	while (!q.empty()) {

		cost = -q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = (x + dx[i]) % N;
			int ny = (y + dy[i]) % N;
			int weight = map[nx][ny];

			if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= N - 1) {

				if (cost + weight < dist[nx][ny]) {

					dist[nx][ny] = cost + weight;
					q.push({ -dist[nx][ny],{ nx, ny } });

				}

			}

		}

	}

	return dist[N - 1][N - 1];

}