#include <iostream>

using namespace std;

int T, Testcase;
int N;
int cor[2][20];
int visit[20];
long long int res = 0;
long long int minValue = 999999999999;

void dfs(int idx);
long long int calc(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> cor[0][i] >> cor[1][i];

		dfs(0);

		cout << "#" << T + 1 << " " << minValue << endl;

		res = 0;
		minValue = 999999999999;

		for (int i = 0; i < N; i++) {

			cor[0][i] = 0;
			cor[1][i] = 0;;
			visit[i] = 0;

		}

	}

	return 0;

}

void dfs(int idx) {

	if (idx == N / 2) {

		res = calc();

		if (res < minValue)
			minValue = res;

		return;

	}

	else {

		for (int i = 0; i < N; i++) {

			if (visit[i] == 0) {

				visit[i] = 1;
				dfs(idx + 1);
				visit[i] = 0;

			}

			else
				break;

		}

	}

}

long long int calc(void) {

	long long int sum_vector[2] = { 0, 0 };
	long long int res = 0;

	for (int j = 0; j < N; j++) {

		if (visit[j] == 1) {
			sum_vector[0] += cor[0][j];
			sum_vector[1] += cor[1][j];
		}
		else {
			sum_vector[0] -= cor[0][j];
			sum_vector[1] -= cor[1][j];
		}

	}

	res = (sum_vector[0] * sum_vector[0]) + (sum_vector[1] * sum_vector[1]);

	return res;

}