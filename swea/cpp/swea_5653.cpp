#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, M, K;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int map[701][701];
vector<pair<pair<int, int>, pair<int, int>>> non_active;
vector<pair<pair<int, int>, pair<int, int>>> active;

bool cmp(const pair<pair<int, int>, pair<int, int>> &a, const pair<pair<int, int>, pair<int, int>> &b)
{
	if (a.second.first < b.second.first)
		return true;
	else
		return false;
}

void solution()
{
	for (int k = 0; k <= K; k++)
	{
		if (!active.empty())
		{
			sort(active.begin(), active.end(), cmp);
			for (int i = active.size() - 1; i >= 0; i--)
			{
				for (int d = 0; d < 4; d++)
				{
					int y = active[i].first.first + dy[d];
					int x = active[i].first.second + dx[d];
					if (map[y][x] == 0)
					{
						map[y][x] = active[i].second.first;
						non_active.push_back(make_pair(make_pair(y, x), make_pair(active[i].second.first, k)));
					}
				}
				if (k == (active[i].second.first + active[i].second.second))
					active.erase(active.begin() + i);
			}
		}
		for (int i = non_active.size() - 1; i >= 0; i--)
		{
			if (k == (non_active[i].second.first + non_active[i].second.second))
			{
				active.push_back(make_pair(make_pair(non_active[i].first.first, non_active[i].first.second), make_pair(non_active[i].second.first, k)));
				non_active.erase(non_active.begin() + i);
			}
		}
	}
}

int main()
{
	setbuf(stdout, NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i + 325][j + 325];
				if (map[i + 325][j + 325] > 0)
					non_active.push_back(make_pair(make_pair(i + 325, j + 325), make_pair(map[i + 325][j + 325], 0)));
			}
		}
		solution();
		cout << "#" << t + 1 << " " << active.size() + non_active.size() << endl;
		memset(map, 0, sizeof(map));
		active.clear();
		non_active.clear();
	}

	return 0;
}