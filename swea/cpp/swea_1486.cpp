#include <iostream>

using namespace std;

int T, Testcase;
int N, B;
int H[20];
int check[20];
int minValue = 9999999;

void dfs(int sum);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> B;

		for (int i = 0; i < N; i++)
			cin >> H[i];

		dfs(0);

		cout << "#" << T + 1 << " " << minValue - B << endl;

		minValue = 9999999;

		for (int i = 0; i < N; i++) {

			H[i] = 0;
			check[i] = 0;

		}

	}

	return 0;

}

void dfs(int sum) {

	if (sum >= B) {

		if (sum < minValue)
			minValue = sum;

		return;

	}

	else {

		for (int i = 0; i < 20; i++) {

			if (check[i] == 0) {

				check[i] = 1;
				dfs(sum + H[i]);
				check[i] = 0;

			}

			else
				break;

		}

	}

}