#include <iostream>

using namespace std;

int T, Testcase, N;

int map[100];
int maxValue = -10000;
int minValue = 10000;
int maxValueind;
int minValueind;
int res;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < 100; i++) {

			cin >> map[i];

		}

		for (int i = 0; i <= N; i++) {

			for (int j = 0; j < 100; j++) {

				if (map[j] >= maxValue) {
					maxValue = map[j];
					maxValueind = j;
				}
				if (map[j] < minValue) {
					minValue = map[j];
					minValueind = j;
				}

			}

			res = maxValue - minValue;

			if (res <= 1)
				break;

			map[maxValueind]--;
			map[minValueind]++;


			maxValue = -10000;
			minValue = 10000;
			maxValueind = 0;
			minValueind = 0;

		}

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;
		maxValue = -10000;
		minValue = 10000;
		maxValueind = 0;
		minValueind = 0;

		for (int i = 0; i < 100; i++)
			map[i] = 0;

	}

	return 0;

}