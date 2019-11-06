#include <iostream>

using namespace std;

int T, Testcase, temp, N;

int road1[100];
int road2[100];
int visit[100];
int max_visit[100];
int num1, num2, res;

void dfs(int idx);

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> temp >> N;

		for (int i = 0; i < 100; i++) {
			road1[i] = 999;
			road2[i] = 999;
		}

		for (int i = 0; i < N; i++) {

			cin >> num1 >> num2;

			if (road1[num1] == 999) {
				road1[num1] = num2;
				max_visit[num1]++;
			}
			else {
				road2[num1] = num2;
				max_visit[num1]++;
			}
		}

		dfs(0);

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

		for (int i = 0; i < 100; i++) {
			max_visit[i] = 0;
			visit[i] = 0;
		}

	}

	return 0;

}

void dfs(int idx) {

	if (idx == 99) {

		res = 1;
		return;

	}

	else if (max_visit[idx] == visit[idx]) {

		return;

	}

	else {

		if (max_visit[idx] == 1 && visit[idx] == 0) {

			visit[idx]++;
			dfs(road1[idx]);
			visit[idx]--;

		}

		else if (max_visit[idx] == 2 && visit[idx] != 2) {

			visit[idx]++;
			dfs(road1[idx]);

			visit[idx]++;
			dfs(road2[idx]);
			visit[idx]--;
			visit[idx]--;

		}

	}

}