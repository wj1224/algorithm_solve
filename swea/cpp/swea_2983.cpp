#include <iostream>
#include <algorithm>
#include <string>

#define MAX_L 200020

using namespace std;

int T, Testcase;

string str;
int L;
int t, g[MAX_L], tg[MAX_L], SA[MAX_L], RANK[MAX_L], LCP[MAX_L];

bool cmp(int x, int y);
void getSA(string str);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> L >> str;

		getSA(str);

		for (int i = 0; i < L; i++)
			RANK[SA[i]] = i;

		int len = 0;

		for (int i = 0; i < L; i++) {

			int k = RANK[i];

			if (k != 0) {

				int j = SA[k - 1];

				while (str[j + len] == str[i + len])
					len++;

				LCP[k] = len;

				if (len != 0)
					len--;

			}

		}

		sort(LCP, LCP + L);

		cout << "#" << T + 1 << " " << LCP[L - 1] << endl;

		for (int i = 0; i < MAX_L; i++) {
			g[i] = 0;
			tg[i] = 0;
			SA[i] = 0;
			RANK[i] = 0;
			LCP[i] = 0;
		}

	}

	return 0;

}


bool cmp(int x, int y) {

	if (g[x] == g[y])
		return g[x + t] < g[y + t];

	return g[x] < g[y];

}
void getSA(string str) {

	t = 1;

	for (int i = 0; i < L; i++) {

		SA[i] = i;
		g[i] = str[i] - 'a';

	}

	while (t <= L) {

		sort(SA, SA + L, cmp);
		tg[SA[0]] = 0;

		for (int i = 1; i < L; i++) {

			if (cmp(SA[i - 1], SA[i]) == 1)
				tg[SA[i]] = tg[SA[i - 1]] + 1;

			else
				tg[SA[i]] = tg[SA[i - 1]];

		}

		for (int i = 0; i < L; i++)
			g[i] = tg[i];

		t *= 2;

	}

}