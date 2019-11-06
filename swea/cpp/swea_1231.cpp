#include <iostream>

using namespace std;

int T, Testcase;

int N;
char tree[100];
int node, right_child, left_child;

void in_order(int n);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < 100; i++)
			tree[i] = NULL;

		if (N % 2 == 0) {

			for (int i = 0; i < N / 2 - 1; i++)
				cin >> node >> tree[i] >> left_child >> right_child;
			cin >> node >> tree[N / 2 - 1] >> left_child;
			for (int i = N / 2; i < N; i++)
				cin >> node >> tree[i];

		}

		else {

			for (int i = 0; i < N / 2; i++)
				cin >> node >> tree[i] >> left_child >> right_child;
			for (int i = N / 2; i < N; i++)
				cin >> node >> tree[i];

		}

		cout << "#" << T + 1 << " ";
		in_order(0);
		cout << endl;

	}

	return 0;

}

void in_order(int n) {

	if (tree[n] != NULL) {

		in_order(2 * n + 1);
		cout << tree[n];
		in_order(2 * n + 2);

	}

}