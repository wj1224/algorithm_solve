#include <iostream>

using namespace std;

int T, Testcase;
int N, K;
int DP[101][1001];
int wei[101];
int val[101];

int main(void) {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> K;

		for (int i = 0; i < N; i++) {

			cin >> wei[i] >> val[i];

		}

		for (int i = 0; i < N; i++) {

			for (int j = 0; j <= K; j++) {

				if (j - wei[i] >= 0) {

					if (DP[i][j] < val[i] + DP[i][j - wei[i]])
						DP[i + 1][j] = val[i] + DP[i][j - wei[i]];
					else
						DP[i + 1][j] = DP[i][j];

				}

				else
					DP[i + 1][j] = DP[i][j];

			}

		}

		cout << "#" << T + 1 << " " << DP[N][K] << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				DP[i][j] = 0;
				wei[i] = 0;
				val[i] = 0;
			}
		}

	}

	return 0;

}