#include <iostream>
#include <queue>

using namespace std;

int T, Testcase, temp;

int num, n = 1;
queue<int> q;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> temp;

		for (int i = 0; i < 8; i++) {
			cin >> num;
			q.push(num);
		}

		while (1) {

			if (q.front() - n <= 0) {

				q.push(0);
				q.pop();
				break;

			}

			q.push(q.front() - n);
			q.pop();
			n++;

			if (n >= 6)
				n = 1;

		}

		cout << "#" << T + 1 << " ";
		for (int i = 0; i < 7; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << q.front() << endl;
		q.pop();

		n = 1;

	}

	return 0;

}