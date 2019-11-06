#include <iostream>

using namespace std;

int T, Testcase;

int map[500][500];
int p, q;
int p_x, p_y, q_x, q_y, sum_x, sum_y;

void map_create(void);

int main() {

	cin >> Testcase;

	map_create();

	for (T = 0; T < Testcase; T++) {

		cin >> p >> q;

		for (int i = 0; i < 150; i++) {

			for (int j = 0; j < 150; j++) {

				if (map[i][j] == p) {
					p_x = i;
					p_y = j;
				}
				if (map[i][j] == q) {
					q_x = i;
					q_y = j;
				}


			}

		}

		sum_x = p_x + q_x;
		sum_y = p_y + q_y;

		cout << "#" << T + 1 << " " << map[sum_x][sum_y] << endl;

	}

	return 0;

}

void map_create(void) {

	int i, j, N;
	int temp = 0;

	map[1][1] = 1;

	N = 2;
	i = 1;
	j = 2;

	while (N <= 41000) {

		map[i++][j--] = N++;

		if (j == 0) {
			temp = i;
			i = j + 1;
			j = temp;
		}

	}

}