#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int map[101][101];
vector<pair<pair<int, int>, pair<int, int>>> dragon_curve[20];

int Calc()
{
	int res = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				res++;
		}
	}
	return res;
}

void DrawCurve()
{
	for (int i = 0; i < N; i++)
	{
		int num = dragon_curve[i][1].second.second;
		int ny = dragon_curve[i][1].first.first;
		int nx = dragon_curve[i][1].first.second;
		for (int j = 0; j < num; j++)
		{
			int K = dragon_curve[i].size();
			for (int k = K - 1; k > 0; k--)
			{
				int dir = dragon_curve[i][k].second.first;
				int gene = dragon_curve[i][k].second.second;
				if (dir == 0)
					dir = 1;
				else if (dir == 1)
					dir = 2;
				else if (dir == 2)
					dir = 3;
				else if (dir == 3)
					dir = 0;
				ny += dy[dir];
				nx += dx[dir];
				dragon_curve[i].push_back(make_pair(make_pair(ny, nx), make_pair(dir, gene)));
				map[ny][nx] = 1;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> x >> y >> d >> g;
		dragon_curve[n].push_back(make_pair(make_pair(y, x), make_pair(d, g)));
		dragon_curve[n].push_back(make_pair(make_pair(y + dy[d], x + dx[d]), make_pair(d, g)));
		map[y][x] = 1;
		map[y + dy[d]][x + dx[d]] = 1;
	}
	DrawCurve();
	cout << Calc() << endl;

	return 0;
}