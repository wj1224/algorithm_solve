#include <iostream>

using namespace std;

int T, Testcase;
int N, K;
int visit[20], num[20];
int res;

void dfs(int idx, int sum);

int main(void) {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> K;

		for (int i = 0; i < N; i++)
			cin >> num[i];


		for (int j = 0; j < N; j++)
			dfs(j, 0);

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

		for (int i = 0; i < 20; i++) {

			num[i] = 0;
			visit[i] = 0;

		}

	}

	return 0;

}


void dfs(int idx, int sum) {

	visit[idx] = 1;

	int sum_check = sum + num[idx];
	int remain = K - sum_check;

	if (sum_check == K)
		res++;

	else if (sum_check < K) {

		for (int k = idx; k < N; k++) {

			if (visit[k] == 0) {

				if (num[k] <= remain)
					dfs(k, sum_check);

			}

		}

	}

	visit[idx] = 0;

}