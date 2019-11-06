#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, L, R, ans, flag;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int check[50][50];
vector<int> map[50][50];

void solution(int cur_y, int cur_x)
{
	int sum_num = 0;
	int cnt_num = 0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push(make_pair(cur_y, cur_x));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		check[y][x] = 1;
		sum_num += map[y][x][0];
		cnt_num++;
		v.push_back(make_pair(y, x));
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (((abs(map[ny][nx][0] - map[y][x][0]) >= L) && (abs(map[ny][nx][0] - map[y][x][0]) <= R)) && check[ny][nx] == 0)
				{
					q.push(make_pair(ny, nx));
					flag = 1;
					check[ny][nx] = 1;
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		map[v[i].first][v[i].second][0] = sum_num / cnt_num;
	}
}

int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			map[i][j].push_back(temp);
		}
	}
	while (1)
	{
		int prev_ans = ans;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i][j] == 0)
					solution(i, j);
			}
		}
		if (flag == 1)
		{
			ans++;
			flag = 0;
		}
		if (prev_ans == ans)
			break;
		memset(check, 0, sizeof(check));
	}
	cout << ans << endl;

	return 0;
}