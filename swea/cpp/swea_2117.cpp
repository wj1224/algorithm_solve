#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int T, Testcase;

int N, M;
vector<pair<int, int>> loc;
vector<vector<int>> manhat_dist(400);
int cost[21];
int maxValue;

int main()
{

	cin >> Testcase;

	for (int i = 0; i < 21; i++)
		cost[i] = (i + 1) * (i + 1) + i * i;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> M;
		int temp;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				if (temp == 1)
					loc.push_back({ i, j });
			}
		}

		int k = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (auto it = loc.begin(); it < loc.end(); it++)
				{
					manhat_dist[k].push_back(abs(i - (*it).first) + abs(j - (*it).second));
				}
				k++;
			}
		}

		for (int i = 0; i < k; i++)
		{
			sort(manhat_dist[i].begin(), manhat_dist[i].end());

			for (int j = 0; j < 21; j++)
			{
				int cnt = 0;

				for (auto it = manhat_dist[i].begin(); it < manhat_dist[i].end(); it++)
				{
					if ((*it) > j)
						break;
					cnt++;
				}

				int profit = M * cnt - cost[j];
				if (profit >= 0 && cnt > maxValue)
					maxValue = cnt;
			}
		}

		cout << "#" << T + 1 << " " << maxValue << endl;

		maxValue = 0;
		loc.clear();
		for (int i = 0; i < k; i++)
			manhat_dist[i].clear();

	}

	return 0;

}