#include <iostream>
#include <string>

using namespace std;

int T, Testcase;

string str;
string ans;

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> str;

		ans = "Exist";

		for (int i = 0; i < str.size() / 2; i++) {

			int j = str.size() - i - 1;

			if (str[i] != str[j] && str[i] != '?' && str[j] != '?') {
				ans = "Not exist";
			}

		}

		cout << "#" << T + 1 << " " << ans << endl;

	}

	return 0;

}