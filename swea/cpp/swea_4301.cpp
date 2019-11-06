#include <iostream>

using namespace std;

int T, Testcase;
int N, M;

int visit[1000][1000];
int maxValue;

void check(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> M;

		check();

		cout << "#" << T + 1 << " " << maxValue << endl;

		maxValue = 0;

		for (int i = 0; i < M; i++) {

			for (int j = 0; j < N; j++) {

				visit[i][j] = 0;

			}

		}

	}

	return 0;

}

void check(void) {

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {

			if (visit[i][j] == 0) {

				maxValue++;
				visit[i][j] = 1;
				if (i > 1)
					visit[i - 2][j] = 1;
				if (i < M - 2)
					visit[i + 2][j] = 1;
				if (j > 1)
					visit[i][j - 2] = 1;
				if (j < N - 2)
					visit[i][j + 2] = 1;

			}

		}

	}

}