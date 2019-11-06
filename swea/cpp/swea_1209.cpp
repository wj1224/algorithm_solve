#define MAX 100

#include <iostream>

using namespace std;

int T, Testcase, temp;

int map[MAX][MAX];
int row_sum[100];
int col_sum[100];
int dia_sum[2];
int maxValue;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> temp;

		for (int i = 0; i < MAX; i++) {

			for (int j = 0; j < MAX; j++) {

				cin >> map[i][j];

				row_sum[i] += map[i][j];
				col_sum[j] += map[i][j];

				if (i == j)
					dia_sum[0] += map[i][j];

				if (i + j == MAX - 1)
					dia_sum[1] += map[i][j];

			}

		}

		for (int i = 0; i < MAX; i++) {

			if (i < 2) {

				if (dia_sum[i] > maxValue)
					maxValue = dia_sum[i];

				dia_sum[i] = 0;

			}

			if (row_sum[i] > maxValue)
				maxValue = row_sum[i];

			if (col_sum[i] > maxValue)
				maxValue = col_sum[i];

			row_sum[i] = 0;
			col_sum[i] = 0;

		}

		cout << "#" << T + 1 << " " << maxValue << endl;

		maxValue = 0;

	}

	return 0;

}