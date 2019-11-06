#include <iostream>
#include <string>

using namespace std;

int T, Testcase;
string A, B;
int res;

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> A >> B;

		int i = 0;

		while (i < A.size()) {

			for (int j = 0; j < B.size(); j++) {

				if (A[i + j] != B[j])
					break;

				if (j == B.size() - 1) {

					i += (B.size() - 1);

				}

			}

			res++;
			i++;

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;

	}

	return 0;

}