#include <iostream>

using namespace std;

int T, Testcase;
int N, score[101];
int check[10001];
int res;

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> score[i];
		}

		check[0] = 1;

		for (int i = 0; i < N; i++) {

			for (int j = 10000; j >= 0; j--) {

				if (check[j] == 1) {

					check[j + score[i]] = 1;

				}

			}

		}

		for (int i = 0; i <= 10000; i++) {
			if (check[i] == 1)
				res++;
		}

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i <= 10000; i++) {
			check[i] = 0;
			if (i <= 100)
				score[i] = 0;
		}

		res = 0;

	}


	return 0;

}