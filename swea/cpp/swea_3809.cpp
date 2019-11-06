#include <iostream>
#include <string>

using namespace std;

int T, Testcase;

int N, length;
int res = -1;
int sign;
string d[1001];
int num[10];
string target_st;
int target;
string temp;

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> d[i];
			num[atoi(d[i].c_str())] = 1;
		}

		for (int i = 0; i < 10; i++) {
			if (num[i] == 0) {
				res = i;
				break;
			}
		}

		if (res == -1) {

			length = 2;
			target = 10;
			target_st = "10";

			while (length <= N) {

				for (int i = 0; i + length - 1 < N; i++) {

					temp = d[i];

					for (int j = 1; j < length; j++) {

						temp += d[i + j];

					}

					if (temp == target_st) {
						target++;
						target_st = to_string(target);
						length = target_st.size();
						break;
					}

					if (i + length == N) {
						res = target;
						sign = 1;
					}

				}

				if (sign == 1)
					break;

			}

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = -1;
		sign = 0;

		for (int i = 0; i < 1001; i++) {
			d[i] = "";
			if (i < 10)
				num[i] = 0;

		}

	}

	return 0;

}