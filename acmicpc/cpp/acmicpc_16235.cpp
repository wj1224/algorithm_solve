#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, tree_y, tree_x, tree_z, ans;
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
vector<pair<int, int>> map[10][10];
vector<int> tree[10][10];

void solution()
{
	for (int tt = 0; tt < K; tt++)
	{
		int death_cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!tree[i][j].empty())
				{
					sort(tree[i][j].begin(), tree[i][j].end());
					for (int k = 0; k < tree[i][j].size(); k++)
					{
						if (tree[i][j][k] <= map[i][j][0].first)
						{
							map[i][j][0].first -= tree[i][j][k];
							tree[i][j][k]++;
						}
						else
							death_cnt++;
					}
					for (int k = 0; k < death_cnt; k++)
					{
						map[i][j][0].first += (tree[i][j][tree[i][j].size() - 1] / 2);
						tree[i][j].pop_back();
					}
					death_cnt = 0;
				}
				map[i][j][0].first += map[i][j][0].second;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!tree[i][j].empty())
				{
					for (int k = 0; k < tree[i][j].size(); k++)
					{
						if (tree[i][j][k] % 5 == 0)
						{
							for (int idx = 0; idx < 8; idx++)
							{
								int ny = i + dy[idx];
								int nx = j + dx[idx];
								if (ny >= 0 && ny < N && nx >= 0 && nx < N)
									tree[ny][nx].push_back(1);
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!tree[i][j].empty())
				ans += tree[i][j].size();
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			map[i][j].push_back(make_pair(5, temp));
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> tree_y >> tree_x >> tree_z;
		tree[tree_y - 1][tree_x - 1].push_back(tree_z);
	}
	solution();
	cout << ans << endl;

	return 0;
}