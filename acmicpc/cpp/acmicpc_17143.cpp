#include <iostream>
#include <vector>

using namespace std;

int R, C, M, r, c, s, d, z, ans;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };
vector<pair<int, pair<int, int>>> map[101][101];

void move_shark()
{
	vector<pair<pair<int, int>, pair<int, pair<int, int>>>> v;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!map[i][j].empty())
			{
				v.push_back(make_pair(make_pair(i, j), make_pair(map[i][j][0].first, make_pair(map[i][j][0].second.first, map[i][j][0].second.second))));
				map[i][j].pop_back();
			}
		}
	}
	while (!v.empty())
	{
		int x = v[v.size() - 1].first.first;
		int y = v[v.size() - 1].first.second;
		int size = v[v.size() - 1].second.first;
		int spd = v[v.size() - 1].second.second.first;
		int dir = v[v.size() - 1].second.second.second;
		if (dir == 1 || dir == 2)
			spd %= (2 * (R - 1));
		else
			spd %= (2 * (C - 1));
		for (int i = 0; i < spd; i++)
		{
			if (dir == 1 || dir == 2)
			{
				if (x == 0 && dir == 1)
					dir = 2;
				else if (x == R - 1 && dir == 2)
					dir = 1;
				x += dx[dir];
			}
			else
			{
				if (y == 0 && dir == 4)
					dir = 3;
				else if (y == C - 1 && dir == 3)
					dir = 4;
				y += dy[dir];
			}
		}
		if (map[x][y].empty())
			map[x][y].push_back(make_pair(size, make_pair(spd, dir)));
		else
		{
			if (map[x][y][0].first < size)
			{
				map[x][y].pop_back();
				map[x][y].push_back(make_pair(size, make_pair(spd, dir)));
			}
		}
		v.pop_back();
	}
}

void catch_shark(int idx)
{
	for (int i = 0; i < R; i++)
	{
		if (!map[i][idx].empty())
		{
			ans += map[i][idx][0].first;
			map[i][idx].pop_back();
			return;
		}
	}
}

int main()
{
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		map[r - 1][c - 1].push_back(make_pair(z, make_pair(s, d)));
	}
	for (int i = 0; i < C; i++)
	{
		catch_shark(i);
		if (i == C - 1)
			break;
		move_shark();
	}
	cout << ans << endl;

	return 0;
}