#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Testcase;

int n;

int res;

int check[10000000];

string map[4][4];

string str;

stack<string> s;

void dfs(int idx, int x, int y);

int main(void) {

	cin >> Testcase;

	for (int T = 0; T < Testcase; T++) {

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				cin >> map[i][j];

			}

		}

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				str = map[i][j];
				dfs(0, i, j);

			}

		}

		for (int i = 0; i < 10000000; i++) {

			if (check[i] == 1) {

				n++;
				check[i] = 0;

			}

		}

		cout << "#" << T + 1 << " " << n << endl;

		n = 0;

	}

	return 0;

}

void dfs(int idx, int x, int y) {

	if (idx == 6) {

		res = atoi(str.c_str());

		check[res] = 1;

		return;

	}

	else {

		if ((x < 3) && (x >= 0) && (y <= 3) && (y >= 0)) {

			s.push(str);
			str = str + map[x + 1][y];
			dfs(idx + 1, x + 1, y);
			str = s.top();
			s.pop();

		}

		if ((x <= 3) && (x > 0) && (y <= 3) && (y >= 0)) {

			s.push(str);
			str = str + map[x - 1][y];
			dfs(idx + 1, x - 1, y);
			str = s.top();
			s.pop();

		}

		if ((x <= 3) && (x >= 0) && (y < 3) && (y >= 0)) {

			s.push(str);
			str = str + map[x][y + 1];
			dfs(idx + 1, x, y + 1);
			str = s.top();
			s.pop();

		}

		if ((x <= 3) && (x >= 0) && (y <= 3) && (y > 0)) {

			s.push(str);
			str = str + map[x][y - 1];
			dfs(idx + 1, x, y - 1);
			str = s.top();
			s.pop();

		}

	}

}