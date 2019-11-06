#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, N;
int map[102][102];
int max_score = -9999999;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> wormhole[11];

int solution(int cur_y, int cur_x, int cur_d)
{
	int res = 0;
	int ny = cur_y;
	int nx = cur_x;
	int dir = cur_d;
	while (1)
	{
		if (map[ny + dy[dir]][nx + dx[dir]] == 5)
		{
			ny += dy[dir];
			nx += dx[dir];
			if (dir == 0)
				dir = 2;
			else if (dir == 1)
				dir = 3;
			else if (dir == 2)
				dir = 0;
			else
				dir = 1;
			res++;
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] == 0)
		{
			ny += dy[dir];
			nx += dx[dir];
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] == 1)
		{
			ny += dy[dir];
			nx += dx[dir];
			if (dir == 0)
				dir = 2;
			else if (dir == 1)
				dir = 0;
			else if (dir == 2)
				dir = 3;
			else if (dir == 3)
				dir = 1;
			res++;
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] == 2)
		{
			ny += dy[dir];
			nx += dx[dir];
			if (dir == 0)
				dir = 2;
			else if (dir == 1)
				dir = 3;
			else if (dir == 2)
				dir = 1;
			else if (dir == 3)
				dir = 0;
			res++;
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] == 3)
		{
			ny += dy[dir];
			nx += dx[dir];
			if (dir == 0)
				dir = 1;
			else if (dir == 1)
				dir = 3;
			else if (dir == 2)
				dir = 0;
			else if (dir == 3)
				dir = 2;
			res++;
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] == 4)
		{
			ny += dy[dir];
			nx += dx[dir];
			if (dir == 0)
				dir = 3;
			else if (dir == 1)
				dir = 2;
			else if (dir == 2)
				dir = 0;
			else if (dir == 3)
				dir = 1;
			res++;
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] >= 6 && map[ny + dy[dir]][nx + dx[dir]] <= 10)
		{
			if ((ny + dy[dir] == wormhole[map[ny + dy[dir]][nx + dx[dir]]][0].first) && (nx + dx[dir] == wormhole[map[ny + dy[dir]][nx + dx[dir]]][0].second))
			{
				int y = wormhole[map[ny + dy[dir]][nx + dx[dir]]][1].first;
				int x = wormhole[map[ny + dy[dir]][nx + dx[dir]]][1].second;
				ny = y;
				nx = x;
			}
			else if ((ny + dy[dir] == wormhole[map[ny + dy[dir]][nx + dx[dir]]][1].first) && (nx + dx[dir] == wormhole[map[ny + dy[dir]][nx + dx[dir]]][1].second))
			{
				int y = wormhole[map[ny + dy[dir]][nx + dx[dir]]][0].first;
				int x = wormhole[map[ny + dy[dir]][nx + dx[dir]]][0].second;
				ny = y;
				nx = x;
			}
		}
		else if (map[ny + dy[dir]][nx + dx[dir]] == -1 || (ny + dy[dir] == cur_y && nx + dx[dir] == cur_x))
			break;
		if (ny == cur_y && nx == cur_x)
			break;
	}
	return res;
}

int main()
{
	setbuf(stdout, NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 0; i <= N + 1; i++)
		{
			for (int j = 0; j <= N + 1; j++)
			{
				if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
					map[i][j] = 5;
				else
				{
					cin >> map[i][j];
					if (map[i][j] >= 6 && map[i][j] <= 10)
						wormhole[map[i][j]].push_back(make_pair(i, j));
				}
			}
		}
		for (int cur_y = 1; cur_y <= N; cur_y++)
		{
			for (int cur_x = 1; cur_x <= N; cur_x++)
			{
				if (map[cur_y][cur_x] == 0)
				{
					for (int cur_d = 0; cur_d < 4; cur_d++)
					{
						int ans = solution(cur_y, cur_x, cur_d);
						if (ans > max_score)
							max_score = ans;
					}
				}
			}
		}
		cout << "#" << t + 1 << " " << max_score << endl;
		memset(map, 0, sizeof(map));
		max_score = -9999999;
		for (int i = 0; i < 11; i++)
			wormhole[i].clear();
	}
	return 0;
}