#include <iostream>
#include <queue>

using namespace std;

int T, Testcase;

int N, W, H;
int minValue = 9999999999;
int map[15][12];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve(int idx);
void shoot(int num);
void copy_arr(int a[15][12], int b[15][12]);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> W >> H;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
			}
		}

		solve(0);

		cout << "#" << T + 1 << " " << minValue << endl;

		minValue = 9999999999;
		fill_n(&map[0][0], 15 * 12, 0);

	}

	return 0;

}

void solve(int idx)
{

	if (idx == N)
	{
		int res = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] != 0)
					res++;
			}
		}
		if (res < minValue)
			minValue = res;
		return;
	}

	for (int i = 0; i < W; i++)
	{
		if (map[H - 1][i] != 0)
		{
			int temp[15][12] = { 0, };
			copy_arr(map, temp);
			shoot(i);
			solve(idx + 1);
			copy_arr(temp, map);
		}
		if (i == W - 1)
			solve(N);
	}

}

void shoot(int num)
{

	queue<pair<int, pair<int, int>>> q;
	queue<int> q2;
	int x, y, nx, ny, len;

	for (int i = 0; i < H; i++)
	{
		if (map[i][num] == 1)
		{
			map[i][num] = 0;
			return;
		}
		else if (map[i][num] != 0)
		{
			q.push({ map[i][num],{ i, num } });
			break;
		}
	}

	while (!q.empty())
	{

		x = q.front().second.first;
		y = q.front().second.second;
		len = q.front().first;
		q.pop();
		map[x][y] = 0;

		// 블럭 파괴
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			while (abs(x - nx) < len && abs(y - ny) < len)
			{
				if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1)
					break;
				if (map[nx][ny] != 0 && map[nx][ny] != 1)
					q.push({ map[nx][ny],{ nx, ny } });
				map[nx][ny] = 0;
				nx += dx[i];
				ny += dy[i];
			}
		}

	}

	// 블럭 내리기
	for (int j = 0; j < W; j++)
	{
		for (int i = H - 1; i >= 0; i--)
		{
			if (map[i][j] != 0)
			{
				q2.push(map[i][j]);
				map[i][j] = 0;
			}
		}
		for (int i = H - 1; i >= 0; i--)
		{
			if (q2.empty())
				break;
			map[i][j] = q2.front();
			q2.pop();
		}
	}

}

void copy_arr(int a[15][12], int b[15][12])
{

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}

}