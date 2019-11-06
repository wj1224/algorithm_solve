#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, Testcase;
int N, idx, cont_sign;
int map[100][100];
int sub_mat[4][20];
vector<pair<int, int>> v;


int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{

			for (int j = 0; j < N; j++)
			{

				for (int k = 0; k < idx; k++)
				{
					if (j >= sub_mat[0][k] && i >= sub_mat[1][k] && j <= sub_mat[2][k] && i <= sub_mat[3][k])
						cont_sign = 1;

				}

				if (cont_sign == 1)
				{
					cont_sign = 0;
					continue;
				}

				if (map[i][j] != 0)
				{
					sub_mat[0][idx] = j;
					sub_mat[1][idx] = i;

					int nj = j;
					while (map[i][nj] != 0 && nj < N)
						nj++;
					sub_mat[2][idx] = nj - 1;

					int ni = i;
					while (map[ni][j] != 0 && ni < N)
						ni++;
					sub_mat[3][idx] = ni - 1;

					idx++;
				}

			}

		}

		for (int i = 0; i < idx; i++)
		{
			int row_size = sub_mat[2][i] - sub_mat[0][i] + 1;
			int col_size = sub_mat[3][i] - sub_mat[1][i] + 1;
			int mat_size = row_size * col_size;
			v.push_back({ mat_size, col_size });
		}

		sort(v.begin(), v.end());

		cout << "#" << T + 1 << " " << idx;
		for (int i = 0; i < idx; i++)
		{
			cout << " " << v[i].second << " " << v[i].first / v[i].second;
		}
		cout << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
				sub_mat[0][j] = 0;
				sub_mat[1][j] = 0;
				sub_mat[2][j] = 0;
				sub_mat[3][j] = 0;
			}
		}
		idx = 0;
		cont_sign = 0;
		v.clear();

	}

	return 0;

}