#include <iostream>

using namespace std;

int N, M, r, c, d, clean, cnt;
int map[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dir[4][4] = { { 3, 2, 1, 0 },{ 0, 3, 2, 1 },{ 1, 0, 3, 2 },{ 2, 1, 0, 3 } };

int main()
{

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	cnt++;
	map[r][c] = 2;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = r + dx[dir[d][i]];
			int ny = c + dy[dir[d][i]];
			if (map[nx][ny] == 0)
			{
				cnt++;
				clean = 1;
				map[nx][ny] = 2;
				r = nx;
				c = ny;
				d = dir[d][i];
				break;
			}
		}

		if (clean == 1)
		{
			clean = 0;
			continue;
		}

		int nx = r + dx[dir[d][1]];
		int ny = c + dy[dir[d][1]];
		if (map[nx][ny] == 1)
			break;
		r = nx;
		c = ny;
	}

	cout << cnt << endl;

	return 0;

}