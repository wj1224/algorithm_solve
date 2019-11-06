#include <iostream>
#include <vector>

using namespace std;

int R, C, T, ans;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<int> air;
vector<vector<vector<int>>> v;

void oper_one()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (v[i][j][0] > 0)
			{
				int x = i;
				int y = j;
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx >= 0 && nx < R && ny >= 0 && ny < C && v[nx][ny][0] != -1)
					{
						v[nx][ny].push_back(v[x][y][0] / 5);
						cnt++;
					}
				}
				v[x][y][0] -= ((v[x][y][0] / 5) * cnt);
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (v[i][j][0] != -1)
			{
				while (v[i][j].size() != 1)
				{
					v[i][j][0] += v[i][j][1];
					v[i][j].erase(v[i][j].begin() + 1);
				}
			}
		}
	}
}

void oper_two()
{
	for (int i = air[0] - 1; i > 0; i--)
	{
		if (v[i][0][0] != -1)
			v[i][0][0] = v[i - 1][0][0];
	}
	for (int i = 0; i < C - 1; i++)
	{
		if (v[0][i][0] != -1)
			v[0][i][0] = v[0][i + 1][0];
	}
	for (int i = 0; i < air[0]; i++)
	{
		if (v[i][C - 1][0] != -1)
			v[i][C - 1][0] = v[i + 1][C - 1][0];
	}
	for (int i = C - 1; i > 0; i--)
	{
		if (v[air[0]][i - 1][0] != -1)
			v[air[0]][i][0] = v[air[0]][i - 1][0];
		else
			v[air[0]][i][0] = 0;
	}

	for (int i = air[1] + 1; i < R - 1; i++)
	{
		if (v[i][0][0] != -1)
			v[i][0][0] = v[i + 1][0][0];
	}
	for (int i = 0; i < C - 1; i++)
	{
		if (v[R - 1][i][0] != -1)
			v[R - 1][i][0] = v[R - 1][i + 1][0];
	}
	for (int i = R - 1; i > air[1]; i--)
	{
		if (v[i][C - 1][0] != -1)
			v[i][C - 1][0] = v[i - 1][C - 1][0];
	}
	for (int i = C - 1; i > 0; i--)
	{
		if (v[air[1]][i - 1][0] != -1)
			v[air[1]][i][0] = v[air[1]][i - 1][0];
		else
			v[air[1]][i][0] = 0;
	}
}

int main()
{
	cin >> R >> C >> T;
	int temp;
	for (int i = 0; i < R; i++)
	{
		v.push_back(vector<vector<int>>());
		for (int j = 0; j < C; j++)
		{
			v[i].push_back(vector<int>());
			cin >> temp;
			v[i][j].push_back(temp);
			if (temp == -1)
				air.push_back(i);
		}
	}
	for (int t = 0; t < T; t++)
	{
		oper_one();
		oper_two();
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (v[i][j][0] != -1)
				ans += v[i][j][0];
		}
	}
	cout << ans << endl;

	return 0;
}