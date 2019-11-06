#include <iostream>
#include <vector>

using namespace std;

int N, K, L;
int map[102][102];
char oper[10001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void get_init(void);
int solve(void);

int main()
{

	get_init();
	int res = solve();

	cout << res << endl;

	return 0;

}

void get_init(void)
{

	cin >> N >> K;
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
				map[i][j] = 1;
		}
	}
	int row, col;
	for (int i = 0; i < K; i++)
	{
		cin >> row >> col;
		map[row][col] = 2;
	}
	cin >> L;
	int temp;
	for (int i = 0; i < L; i++)
	{
		cin >> temp;
		cin >> oper[temp];
	}

}

int solve(void)
{

	map[1][1] = 3;
	vector<pair<int, int>> v;
	int cnt = 0, dir = 0, nx, ny;
	v.push_back({ 1, 1 });

	while (1)
	{
		if (oper[cnt] == 'D')
		{
			if (dir == 0 || dir == 1 || dir == 2)
				dir++;
			else if (dir == 3)
				dir = 0;
		}
		else if (oper[cnt] == 'L')
		{
			if (dir == 0)
				dir = 3;
			else if (dir == 1 || dir == 2 || dir == 3)
				dir--;
		}

		auto it = v.end() - 1;
		nx = (*it).first + dx[dir];
		ny = (*it).second + dy[dir];

		if (map[nx][ny] == 1 || map[nx][ny] == 3)
			return cnt + 1;
		else if (map[nx][ny] == 2)
		{
			map[nx][ny] = 3;
			v.push_back({ nx, ny });
		}
		else
		{
			map[nx][ny] = 3;
			map[v[0].first][v[0].second] = 0;
			v.erase(v.begin());
			v.push_back({ nx, ny });
		}
		cnt++;
	}

}