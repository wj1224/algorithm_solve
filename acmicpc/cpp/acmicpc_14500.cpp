#include <iostream>

using namespace std;

int N, M;
int map[500][500];
int dx[9] = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
int dy[9] = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };
int tetro1[2][4] = { { 8, 0, 0, 0 },{ 8, 1, 1, 1 } };
int tetro2[4] = { 8, 0, 1, 2 };
int tetro3[8][4] = { { 8, 1, 1, 0 },{ 8, 3, 0, 0 },{ 8, 0, 1, 1 },{ 8, 1, 2, 2 },{ 8, 0, 3, 3 },{ 8, 1, 0, 0 },{ 8, 2, 1, 1 },{ 8, 3, 2, 2 } };
int tetro4[4][4] = { { 8, 1, 0, 1 },{ 8, 0, 3, 0 },{ 8, 3, 0, 3 },{ 8, 0, 1, 0 } };
int tetro5[4][4] = { { 8, 0, 0, 6 },{ 8, 1, 1, 4 },{ 8, 0, 0, 7 },{ 8, 1, 1, 7 } };
int maxValue = -9999999;

int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int nx = i;
				int ny = j;
				for (int l = 0; l < 4; l++)
				{
					nx += dx[tetro1[k][l]];
					ny += dy[tetro1[k][l]];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					{
						res = 0;
						break;
					}
					res += map[nx][ny];
				}
				if (res > maxValue)
					maxValue = res;
				res = 0;
			}

			int nx = i;
			int ny = j;
			for (int l = 0; l < 4; l++)
			{
				nx += dx[tetro2[l]];
				ny += dy[tetro2[l]];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				{
					res = 0;
					break;
				}
				res += map[nx][ny];
			}
			if (res > maxValue)
				maxValue = res;
			res = 0;

			for (int k = 0; k < 8; k++)
			{
				int nx = i;
				int ny = j;
				for (int l = 0; l < 4; l++)
				{
					nx += dx[tetro3[k][l]];
					ny += dy[tetro3[k][l]];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					{
						res = 0;
						break;
					}
					res += map[nx][ny];
				}
				if (res > maxValue)
					maxValue = res;
				res = 0;
			}

			for (int k = 0; k < 4; k++)
			{
				int nx = i;
				int ny = j;
				for (int l = 0; l < 4; l++)
				{
					nx += dx[tetro4[k][l]];
					ny += dy[tetro4[k][l]];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					{
						res = 0;
						break;
					}
					res += map[nx][ny];
				}
				if (res > maxValue)
					maxValue = res;
				res = 0;
			}

			for (int k = 0; k < 4; k++)
			{
				int nx = i;
				int ny = j;
				for (int l = 0; l < 4; l++)
				{
					nx += dx[tetro5[k][l]];
					ny += dy[tetro5[k][l]];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					{
						res = 0;
						break;
					}
					res += map[nx][ny];
				}
				if (res > maxValue)
					maxValue = res;
				res = 0;
			}
		}
	}

	cout << maxValue << endl;

	return 0;

}