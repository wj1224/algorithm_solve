#include <iostream>

using namespace std;

int T, Testcase;

int N, K;
int map[8][8];
int visit[8][8];
int start[5][2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 , 0 };
int maxValue, check;

void solve1(int idx, int x, int y, int cur_hei);
void solve2(int idx, int x, int y, int cur_hei);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> K;
		int max_hei = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > max_hei)
					max_hei = map[i][j];
			}
		}
		int k = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == max_hei)
				{
					start[k][0] = i;
					start[k][1] = j;
					k++;
				}
			}
		}

		for (int l = 0; l < k; l++)
		{
			visit[start[l][0]][start[l][1]] = 1;
			solve1(1, start[l][0], start[l][1], map[start[l][0]][start[l][1]]);
			solve2(1, start[l][0], start[l][1], map[start[l][0]][start[l][1]]);
			visit[start[l][0]][start[l][1]] = 0;
		}

		cout << "#" << T + 1 << " " << maxValue << endl;

		maxValue = 0;
		check = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				start[i][j] = 0;
			}
		}

	}

	return 0;

}

void solve1(int idx, int x, int y, int cur_hei)
{

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= N - 1))
		{
			if (cur_hei > map[nx][ny] && visit[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				solve1(idx + 1, nx, ny, map[nx][ny]);
				visit[nx][ny] = 0;
			}
		}

		if (i == 3)
		{
			if (idx > maxValue)
				maxValue = idx;
		}
	}

}

void solve2(int idx, int x, int y, int cur_hei)
{

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= N - 1))
		{
			if (check == 0)
			{
				for (int j = K; j >= 1; j--)
				{
					if (cur_hei > map[nx][ny] - j && visit[nx][ny] == 0)
					{
						check = 1;
						visit[nx][ny] = 1;
						solve2(idx + 1, nx, ny, map[nx][ny] - j);
						check = 0;
						visit[nx][ny] = 0;
					}
					else
						break;
				}
			}
			if (cur_hei > map[nx][ny] && visit[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				solve2(idx + 1, nx, ny, map[nx][ny]);
				visit[nx][ny] = 0;
			}
		}

		if (i == 3)
		{
			if (idx > maxValue)
				maxValue = idx;
		}
	}

}