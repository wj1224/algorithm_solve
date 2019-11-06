#include <iostream>
#include <vector>

using namespace std;

int N, M;
int minValue = 99999999;
int map[50][50];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> chicken_alive;

int calc()
{
	int sum_dist = 0;
	vector<int> min_dist;

	for (int i = 0; i < home.size(); i++)
	{
		int dist = 99999999;
		for (int j = 0; j < chicken_alive.size(); j++)
		{
			if ((abs(chicken[chicken_alive[j]].first - home[i].first) + abs(chicken[chicken_alive[j]].second - home[i].second)) < dist)
				dist = (abs(chicken[chicken_alive[j]].first - home[i].first) + abs(chicken[chicken_alive[j]].second - home[i].second));
		}
		min_dist.push_back(dist);
	}
	for (int i = 0; i < min_dist.size(); i++)
		sum_dist += min_dist[i];

	return sum_dist;
}

void dfs(int idx)
{
	if (idx > chicken.size())
		return;
	if (chicken_alive.size() == M)
	{
		int res = calc();
		if (res < minValue)
			minValue = res;
		return;
	}
	chicken_alive.push_back(idx);
	dfs(idx + 1);
	chicken_alive.pop_back();
	dfs(idx + 1);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	dfs(0);
	cout << minValue << endl;

	return 0;
}