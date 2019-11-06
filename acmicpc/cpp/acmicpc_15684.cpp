#include <iostream>

using namespace std;

int N, M, H, a, b;
int map[30][10];
int minValue = 4;

void dfs(int idx, int x, int y);
int calc();

int main()
{

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = 2;
	}

	dfs(0, 0, 0);
	if (minValue == 4)
		minValue = -1;

	cout << minValue << endl;

	return 0;

}

void dfs(int idx, int x, int y)
{

	if (idx >= 4)
		return;

	int res = calc();
	if (res == 1)
	{
		if (idx < minValue)
		{
			minValue = idx;
		}
		return;
	}

	if (y >= N - 1)
	{
		dfs(idx, x + 1, 0);
		return;
	}

	if (x >= H)
		return;

	if (map[x][y] != 1 && map[x][y] != 2 && map[x][y + 1] != 1)
	{
		map[x][y] = 1;
		map[x][y + 1] = 2;
		dfs(idx + 1, x, y + 1);
		map[x][y] = 0;
		map[x][y + 1] = 0;
	}
	if (idx + 1 < minValue)
		dfs(idx, x, y + 1);

}

int calc()
{

	for (int i = 0; i < N; i++)
	{
		int nx = 0;
		int ny = i;

		while (nx != H)
		{
			if (map[nx][ny] == 1)
			{
				nx++;
				ny++;
			}
			else if (map[nx][ny] == 2)
			{
				nx++;
				ny--;
			}
			else
				nx++;
		}

		if (ny != i)
			return 0;
	}

	return 1;

}