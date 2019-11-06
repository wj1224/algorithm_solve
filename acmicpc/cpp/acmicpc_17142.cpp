#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, num;
int ans = 9999999;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<vector<int>> lab;
vector<vector<int>> cp;
vector<pair<int, int>> v;
vector<pair<int, int>> v2;

void virus()
{
	queue<pair<int, int>> q;
	int cnt = 0;
	int num_cnt = 0;

	for (int i = 0; i < v2.size(); i++)
	{
		q.push(make_pair(v2[i].first, v2[i].second));
		lab[v2[i].first][v2[i].second] = 3;
	}

	while (1)
	{
		if (q.empty() || num_cnt == num)
			break;
		int n = q.size();
		for (int i = 0; i < n; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{
					if (lab[nx][ny] == 0 || lab[nx][ny] == 2)
					{
						if (lab[nx][ny] == 0)
							num_cnt++;
						lab[nx][ny] = 3;
						q.push(make_pair(nx, ny));
					}
				}
			}
			q.pop();
		}
		cnt++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (lab[i][j] == 0)
				return;
		}
	}
	if (cnt < ans)
		ans = cnt;
	return;
}

void dfs(int idx)
{
	if (v2.size() == M)
	{
		virus();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				lab[i][j] = cp[i][j];
		return;
	}
	if (idx >= v.size())
		return;

	v2.push_back(make_pair(v[idx].first, v[idx].second));
	dfs(idx + 1);
	v2.pop_back();
	dfs(idx + 1);
}

int main()
{
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++)
	{
		lab.push_back(vector<int>());
		cp.push_back(vector<int>());
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			lab[i].push_back(temp);
			cp[i].push_back(temp);
			if (temp == 2)
				v.push_back(make_pair(i, j));
			if (temp == 0)
				num++;
		}
	}
	dfs(0);
	if (ans == 9999999)
		ans = -1;
	cout << ans << endl;

	return 0;
}