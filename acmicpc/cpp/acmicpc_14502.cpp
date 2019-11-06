#include <iostream>
#include <queue>

using namespace std;

int N, M;
int maxValue = -9999999;
int map[8][8];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int idx, int x, int y);
void copy_arr(int a[8][8], int b[8][8]);
void virus();
int calc();

int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	dfs(0, 0, 0);

	cout << maxValue << endl;

	return 0;

}

void dfs(int idx, int x, int y)
{
	if (idx == 3)
	{
		int temp[8][8];
		copy_arr(temp, map);
		virus();
		int res = calc();

		if (res > maxValue)
			maxValue = res;

		copy_arr(map, temp);

		return;
	}

	if (x >= N)
		return;
	if (y >= M)
	{
		dfs(idx, x + 1, 0);
		return;
	}

	if (map[x][y] == 0)
	{
		map[x][y] = 1;
		dfs(idx + 1, x, y + 1);
		map[x][y] = 0;
	}
	dfs(idx, x, y + 1);
}

void copy_arr(int a[8][8], int b[8][8])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			a[i][j] = b[i][j];
}

void virus()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = r + dx[i];
			int ny = c + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (map[nx][ny] == 0)
				{
					map[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int calc()
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}