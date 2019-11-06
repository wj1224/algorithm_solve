#include <iostream>

using namespace std;

int T, Testcase, N;
int col[10], cross1[21], cross2[21];
int res;

void dfs(int idx);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		dfs(0);

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

	}

	return 0;

}

void dfs(int idx) {

	if (idx == N) {

		res++;

		return;

	}

	else {

		for (int i = 0; i < N; i++) {

			if ((col[i] == 0) && (cross1[idx + i] == 0) && (cross2[N + (idx - i) + 1] == 0)) {

				col[i] = 1;
				cross1[idx + i] = 1;
				cross2[N + (idx - i) + 1] = 1;
				dfs(idx + 1);
				col[i] = 0;
				cross1[idx + i] = 0;
				cross2[N + (idx - i) + 1] = 0;

			}

		}

	}

}