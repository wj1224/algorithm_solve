#include <iostream>

using namespace std;

int T, Testcase, temp;
int N, M, res;

int solve(int idx, int num);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> temp >> N >> M;

		res = solve(1, N);

		cout << "#" << T + 1 << " " << res << endl;

	}

	return 0;

}

int solve(int idx, int num) {

	if (idx == M)
		return num;

	solve(idx + 1, N * num);

}