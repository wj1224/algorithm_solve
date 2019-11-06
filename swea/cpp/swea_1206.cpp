#include <iostream>

using namespace std;

int Testcase, T;

int w, sum;

int h[1000];

int map[255][1000];

int main(void) {

	Testcase = 10;

	for (int T = 0; T < Testcase; T++) {

		cin >> w;

		for (int i = 0; i < w; i++) {

			cin >> h[i];

			for (int j = 0; j < h[i]; j++) {

				map[j][i] = 1;

			}

		}

		for (int i = 2; i < w - 2; i++) {

			for (int j = h[i] - 1; j >= 0; j--) {

				if (map[j][i] == 1) {

					if ((map[j][i - 1] == 0) && (map[j][i - 2] == 0) && (map[j][i + 1] == 0) && (map[j][i + 2] == 0)) {

						sum++;

					}

					else {

						break;

					}

				}

			}

		}

		cout << "#" << T + 1 << " " << sum << endl;

		sum = 0;

		fill(&map[0][0], &map[254][1000], 0);
		fill(&h[0], &h[1000], 0);

	}

	return 0;

}