#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, ans, num_eat;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<vector<pair<int, int>>> map;
vector<pair<pair<int, int>, int>> shark;
vector<pair<pair<int, int>, int>> fish;

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first.first < b.first.first)
			return true;
		else if (a.first.first == b.first.first)
		{
			if (a.first.second < b.first.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void search_fish()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;

	q.push(make_pair(make_pair(shark[0].first.first, shark[0].first.second), make_pair(shark[0].second, 0)));
	map[shark[0].first.first][shark[0].first.second].second = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int s = q.front().second.first;
		int d = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (map[ny][nx].first <= s && map[ny][nx].second > d + 1)
				{
					if (map[ny][nx].first < s && map[ny][nx].first > 0)
						fish.push_back(make_pair(make_pair(ny, nx), d + 1));
					q.push(make_pair(make_pair(ny, nx), make_pair(s, d + 1)));
					map[ny][nx].second = d + 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j].second = 99999999;
}

void eat_fish()
{
	sort(fish.begin(), fish.end(), cmp);
	map[fish[0].first.first][fish[0].first.second].first = 0;
	shark[0].first.first = fish[0].first.first;
	shark[0].first.second = fish[0].first.second;
	ans += fish[0].second;
	num_eat++;
	if (num_eat == shark[0].second)
	{
		num_eat = 0;
		shark[0].second++;
	}
	fish.clear();
}

int main()
{
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		map.push_back(vector<pair<int, int>>());
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			map[i].push_back(make_pair(temp, 99999999));
			if (temp == 9)
			{
				shark.push_back(make_pair(make_pair(i, j), 2));
				map[i][j].first = 0;
			}
		}
	}
	while (1)
	{
		search_fish();
		if (fish.empty())
			break;
		eat_fish();
	}
	cout << ans << endl;

	return 0;
}