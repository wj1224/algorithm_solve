#include <iostream>

using namespace std;

int T, Testcase;

int N;
int maxValue = -1;
int maxInd;
int map[1000][1000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve(int x, int y, int num, int cnt);

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
				solve(i, j, map[i][j], 1);
			}
		}

		cout << "#" << T + 1 << " " << maxInd << " " << maxValue << endl;

		maxValue = -1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
			}
		}

	}

	return 0;

}

void solve(int x, int y, int num, int cnt)
{

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= N - 1))
		{
			if (map[x][y] + 1 == map[nx][ny])
			{
				solve(nx, ny, num, cnt + 1);
			}
		}

		if (k == 3)
		{
			if (cnt == maxValue)
			{
				if (num < maxInd)
				{
					maxValue = cnt;
					maxInd = num;
				}
			}
			else if (cnt > maxValue)
			{
				maxValue = cnt;
				maxInd = num;
			}
		}

	}

}