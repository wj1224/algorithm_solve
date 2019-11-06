#include <iostream>
#include <string>

using namespace std;

int T, Testcase;

string str1;

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		int cnt = 0;
		char str2[50];

		cin >> str1;

		for (int i = 0; i < str1.size(); i++)
			str2[i] = '0';

		for (int i = 0; i < str1.size(); i++) {

			if (str1[i] != str2[i]) {
				for (int j = i; j < str1.size(); j++)
					str2[j] = str1[i];
				cnt++;
			}

		}

		cout << "#" << T + 1 << " " << cnt << endl;

	}

	return 0;

}