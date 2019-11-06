#define MAX_VAL 1e18

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, Testcase;

int N, M, stnum, ednum;
vector<vector<pair<int, long long int>>> v(100001);
queue<int> q;
int check[100001];
long long int dist[100001];

void SPFA(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> M >> stnum >> ednum;

		int temp1, temp2, temp3;
		for (int i = 0; i < M; i++)
		{
			cin >> temp1 >> temp2 >> temp3;
			v[temp1].push_back({ temp2, temp3 });
			v[temp2].push_back({ temp1, temp3 });
		}

		for (int i = 0; i < 100001; i++)
			dist[i] = MAX_VAL;

		SPFA();

		cout << "#" << T + 1 << " " << dist[ednum] << endl;

		for (int i = 0; i < 100001; i++)
			v[i].clear();

	}

	return 0;

}

void SPFA(void)
{

	long long int cost = 0;
	int edge = stnum;
	dist[edge] = cost;

	q.push(edge);
	check[edge] = 1;

	while (!q.empty())
	{
		edge = q.front();
		cost = dist[edge];
		check[edge] = 0;
		q.pop();

		for (auto it = v[edge].begin(); it < v[edge].end(); it++)
		{
			int weight = (*it).second;

			if (cost + weight < dist[(*it).first])
			{
				dist[(*it).first] = cost + weight;

				if (check[(*it).first] == 0)
				{
					q.push((*it).first);
					check[(*it).first] = 1;
				}
			}
		}

	}

}