#include <iostream>

using namespace std;

int T, Testcase;
int N, M, K;

int arrival[100];
int n, res = 1;

int check(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> M >> K;

		for (int i = 0; i < N; i++) {
			cin >> arrival[i];
			if (arrival[i] < M) {
				res = 0;
			}
		}

		if (res == 1)
			res = check();

		if (res == 0)
			cout << "#" << T + 1 << " " << "Impossible" << endl;
		else if (res == 1)
			cout << "#" << T + 1 << " " << "Possible" << endl;

		res = 1;

		for (int i = 0; i < N; i++)
			arrival[i] = 0;

	}

	return 0;

}

int check(void) {

	int gap = M;
	int num_bread = K;
	int visit = 0;

	while (visit < N) {

		for (int i = 0; i < N; i++) {

			if (arrival[i] >= gap && arrival[i] < gap + M) {

				if (num_bread <= 0)
					return 0;

				num_bread--;
				visit++;

			}

		}

		gap += M;
		num_bread += K;

	}

	return 1;

}