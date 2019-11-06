#include <iostream>
#include <string>

using namespace std;

int T, Testcase, N;

string s1;
string s2;

int check, res;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N >> s1 >> s2;

		for (int i = 0; i <= s2.size() - s1.size(); i++) {

			for (int j = 0; j < s1.size(); j++) {

				if (s1[j] == s2[i + j])
					check++;

			}

			if (check == s1.size())
				res++;
			check = 0;

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

	}

	return 0;

}