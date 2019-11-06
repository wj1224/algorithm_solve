#define MAX 100

#include <iostream>
#include <stack>

using namespace std;

int T, Testcase, N;

int map[MAX][MAX];
int res;
stack<int> s;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				cin >> map[i][j];

			}

		}

		for (int j = 0; j < N; j++) {

			s.push(0);

			for (int i = 0; i < N; i++) {

				if (map[i][j] == 2 && s.top() == 1) {
					res++;
					s.pop();
				}
				else if (map[i][j] == 1 && s.top() != 1)
					s.push(map[i][j]);

			}

			while (!s.empty())
				s.pop();

		}


		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

	}

	return 0;

}