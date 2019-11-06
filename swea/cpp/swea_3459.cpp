#include <iostream>
#include <math.h>

using namespace std;

int T, Testcase;
long long int N;
int level, res;

void main_func(int idx, long long int x);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;
		level = log(N) / log(2);

		if (N == 1)
			res = 2;
		else if (N == 2 || N == 3)
			res = 1;
		else
			main_func(0, 1);

		if (res == 1)
			cout << "#" << T + 1 << " " << "Alice" << endl;
		else
			cout << "#" << T + 1 << " " << "Bob" << endl;

	}

	return 0;

}

void main_func(int idx, long long int x) {

	if (x > N) {

		if (idx % 2 == 0)
			res = 1; // Alice win
		else if (idx % 2 == 1)
			res = 2; // Bob win

	}

	else {

		if (idx % 2 == 0 && level % 2 == 1)
			main_func(idx + 1, 2 * x);
		else if (idx % 2 == 0 && level % 2 == 0)
			main_func(idx + 1, 2 * x + 1);
		else if (idx % 2 == 1 && level % 2 == 1)
			main_func(idx + 1, 2 * x + 1);
		else if (idx % 2 == 1 && level % 2 == 0)
			main_func(idx + 1, 2 * x);

	}

}