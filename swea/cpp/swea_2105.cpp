#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, Testcase;

int N;
int map[20][20];
int visit[20][20];
int dx[4] = { 1, 1, -1, -1 };
int dy[4] = { 1, -1, -1, 1 };
int res = -1;
vector<int> v;
vector<int>::iterator it;

void solve(int idx, int x, int y, int start_num, int start_x, int start_y, int dir);

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
				v.clear();
				v.push_back(-1);
				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < N; l++)
					{
						visit[k][l] = 0;
					}
				}
				visit[i][j] = 2;
				solve(0, i, j, map[i][j], i, j, 0);
			}
		}

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
			}
		}
		res = -1;

	}

	return 0;

}

void solve(int idx, int x, int y, int start_num, int start_x, int start_y, int dir)
{
	if (dir == 4)
		return;

	if (idx > 2 && x == start_x && y == start_y)
	{
		if (idx > res)
			res = idx;
		return;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= N - 1)
	{
		if (visit[nx][ny] == 0)
		{
			it = find(v.begin(), v.end(), map[nx][ny]);
			if (it == v.end() && start_num != map[nx][ny])
			{
				visit[nx][ny] = 1;
				v.push_back(map[nx][ny]);
				solve(idx + 1, nx, ny, start_num, start_x, start_y, dir);
				visit[nx][ny] = 0;
				it = find(v.begin(), v.end(), map[nx][ny]);
				v.erase(it);
			}
		}
		else if (visit[nx][ny] == 2)
		{
			solve(idx + 1, nx, ny, start_num, start_x, start_y, dir);
		}
	}

	solve(idx, x, y, start_num, start_x, start_y, dir + 1);

}