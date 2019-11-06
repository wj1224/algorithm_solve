#include <iostream>

using namespace std;

int T, Testcase;

int p, q;
int cycle, st, cur, idx, itg;
int remain[100001];
char res[100001];

void solve(void);
void print_func(void);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> p >> q;

		solve();

		print_func();

		for (int i = 0; i < 100001; i++) {
			remain[i] = 0;
			res[i] = 0;
		}

		cycle = 0;
		st = 0;
		cur = 0;
		idx = 0;
		itg = 0;

	}

	return 0;

}

void solve(void) {

	cur = p;

	while (cur != 0) {

		if (idx == 0) {

			itg = cur / q;
			if (cur % q != 0)
				res[idx++] = '.';

		}

		else
			res[idx++] = (cur / q) + 48;

		cur %= q;

		if (remain[cur] != 0) {

			cycle = 1;
			st = remain[cur];

		}

		if (cycle == 1)
			break;

		else
			remain[cur] = idx;

		cur *= 10;

	}

}

void print_func(void) {

	cout << "#" << T + 1 << " " << itg;

	if (cycle == 0) {

		for (int i = 0; i < idx; i++)
			cout << res[i];

	}

	else {

		for (int i = 0; i < idx; i++) {

			if (i == st) {

				cout << "(";
				for (int j = st; j < idx; j++)
					cout << res[j];
				cout << ")";

				break;

			}

			else {

				cout << res[i];

			}

		}

	}

	cout << endl;

}