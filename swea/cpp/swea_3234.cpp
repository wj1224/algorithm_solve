#include <iostream>

using namespace std;

int T, Testcase;

int N;
int wei[9];
int res;
int visit[9];
int all_sum;
int fact[10] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int square[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 1024 };

void dfs(int idx, int left_sum, int right_sum, int remain);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> wei[i];
			all_sum += wei[i];
		}

		dfs(0, 0, 0, all_sum);

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i < N; i++)
			wei[i] = 0;
		res = 0;
		all_sum = 0;

	}

	return 0;

}

void dfs(int idx, int left_sum, int right_sum, int remain) {

	if (right_sum > left_sum)
		return;

	if (idx == N) {

		res++;

		return;

	}

	else if (left_sum >= right_sum + remain) {

		res += (fact[N - idx] * square[N - idx]);

		return;

	}

	for (int i = 0; i < N; i++) {

		if (visit[i] == 0) {

			visit[i] = 1;

			dfs(idx + 1, left_sum + wei[i], right_sum, remain - wei[i]);
			dfs(idx + 1, left_sum, right_sum + wei[i], remain - wei[i]);

			visit[i] = 0;

		}

	}

}