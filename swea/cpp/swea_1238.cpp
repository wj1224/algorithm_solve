#include <iostream>
#include <queue>

using namespace std;

int T, Testcase;

int N, start;
int from, to;
int map[101][101];
int dist[101];
int maxValue, maxInd;

priority_queue<pair<int, int>> q;

void dijkstra(void);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> start;

		for (int i = 0; i < N / 2; i++) {

			cin >> from >> to;
			map[from][to] = 1;

		}

		for (int i = 0; i < 101; i++)
			dist[i] = 1000;

		dijkstra();

		for (int i = 0; i < 101; i++) {
			if (dist[i] >= maxValue && dist[i] < 1000) {
				maxValue = dist[i];
				maxInd = i;
			}
		}

		cout << "#" << T + 1 << " " << maxInd << endl;

		maxValue = 0;

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				map[i][j] = 0;
			}
		}

	}

	return 0;

}

void dijkstra(void) {

	int cost = 0, num = 0;
	dist[start] = 0;
	q.push({ -dist[start], start });

	while (!q.empty()) {

		cost = -q.top().first;
		num = q.top().second;
		q.pop();

		for (int i = 0; i < 100; i++) {

			int weight = 1;

			if (map[num][i] == 1) {

				if (cost + weight < dist[i]) {

					dist[i] = cost + weight;
					q.push({ -dist[i], i });

				}

			}

		}

	}

}