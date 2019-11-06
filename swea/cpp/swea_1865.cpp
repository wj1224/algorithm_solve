#include <iostream>

using namespace std;

int T, Testcase;

int N;
double P[16][16];
double maxValue = -1;
int visited[16];

void dfs(int idx, double prob);

int main() {

	cin >> Testcase;
	cout << fixed;
	cout.precision(6);

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> P[i][j];
				P[i][j] /= 100;
			}
		}

		dfs(0, 1);

		cout << "#" << T + 1 << " " << maxValue * 100 << endl;

		maxValue = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				P[i][j] = 0;
				visited[i] = 0;
			}
		}

	}

	return 0;

}

void dfs(int idx, double prob) {

	if (prob <= maxValue)
		return;

	if (idx == N) {

		if (prob > maxValue) {

			maxValue = prob;

		}

		return;

	}

	for (int i = 0; i < N; i++) {

		if (visited[i] == 0) {

			visited[i] = 1;
			dfs(idx + 1, prob * P[idx][i]);
			visited[i] = 0;

		}

	}

}