#include <iostream>

using namespace std;

int T, Testcase, N;
char map[49][49];
int map2[49][49];
int sum;

void sum_func(int idx, int start, int end);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				cin >> map[i][j];
				map2[i][j] = map[i][j] - '0';

			}

		}

		sum_func(0, N / 2, N / 2);

		cout << "#" << T + 1 << " " << sum << endl;

		sum = 0;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				map[i][j] = 0;
				map2[i][j] = 0;

			}

		}

	}

	return 0;

}

void sum_func(int idx, int start, int end) {

	if (idx == N)
		return;

	else if (idx < (N / 2)) {

		for (int i = start; i <= end; i++)
			sum += map2[idx][i];
		sum_func(idx + 1, start - 1, end + 1);

	}

	else if (idx >= (N / 2)) {

		for (int i = start; i <= end; i++)
			sum += map2[idx][i];
		sum_func(idx + 1, start + 1, end - 1);

	}

}