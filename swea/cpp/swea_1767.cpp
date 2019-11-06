#include <iostream>

using namespace std;

int T, Testcase;

int N, core_cnt, maxCore;
int minValue = 9999999999;
int map[12][12];
int core[12][2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve(int idx, int numCore, int sum);
int ConnectCheck(int x, int y, int dir);
int ConnectCore(int x, int y, int dir, int mode);

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
				if (map[i][j] == 1 && i != 0 && i != N - 1 && j != 0 && j != N - 1)
				{
					core[core_cnt][0] = i;
					core[core_cnt][1] = j;
					core_cnt++;
				}
			}
		}

		solve(0, 0, 0);

		cout << "#" << T + 1 << " " << minValue << endl;

		fill_n(&map[0][0], 12 * 12, 0);
		fill_n(&core[0][0], 12 * 2, 0);
		core_cnt = 0;
		maxCore = 0;
		minValue = 9999999999;

	}

	return 0;

}

void solve(int idx, int numCore, int sum)
{

	if (idx == core_cnt)
	{
		if (numCore > maxCore)
		{
			maxCore = numCore;
			minValue = sum;
		}
		else if (numCore == maxCore && sum < minValue)
			minValue = sum;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (ConnectCheck(core[idx][0], core[idx][1], i) == 1)
		{
			solve(idx + 1, numCore + 1, sum + ConnectCore(core[idx][0], core[idx][1], i, 0));
			ConnectCore(core[idx][0], core[idx][1], i, 1);
		}
	}
	solve(idx + 1, numCore, sum);

}

int ConnectCheck(int x, int y, int dir)
{

	int nx = x;
	int ny = y;

	while (nx != 0 && nx != N - 1 && ny != 0 && ny != N - 1)
	{
		nx += dx[dir];
		ny += dy[dir];

		if (map[nx][ny] != 0)
			return 0;
	}

	return 1;

}

int ConnectCore(int x, int y, int dir, int mode)
{

	int len = 0;
	int nx = x;
	int ny = y;

	while (nx != 0 && nx != N - 1 && ny != 0 && ny != N - 1)
	{
		nx += dx[dir];
		ny += dy[dir];

		if (mode == 0)
		{
			map[nx][ny] = 2;
			len++;
		}
		else
			map[nx][ny] = 0;
	}

	return len;

}