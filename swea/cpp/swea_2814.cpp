#include <iostream>

using namespace std;

int T, Testcase;
int N, M;
int temp[2];
int map[11][11];
int visit[11];
int maxValue;

void dfs(int idx, int length);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> M;

		for (int i = 0; i < M; i++) {

			cin >> temp[0] >> temp[1];

			map[temp[0]][temp[1]] = 1;
			map[temp[1]][temp[0]] = 1;

		}

		for (int j = 1; j <= N; j++) {
			visit[j] = 1;
			dfs(j, 1);
			visit[j] = 0;
		}

		cout << "#" << T + 1 << " " << maxValue << endl;

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				map[i][j] = 0;
				visit[i] = 0;
			}
		}

		maxValue = 0;

	}

	return 0;

}

void dfs(int idx, int length) {

	if (length > maxValue) {
		maxValue = length;
	}

	for (int i = 1; i <= N; i++) {

		if (map[idx][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			dfs(i, length + 1);
			visit[i] = 0;
		}
	}

}