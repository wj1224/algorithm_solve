#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[8][8];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cctv1[4] = { 0, 1, 2, 3 };
int cctv2[2][2] = { { 0, 2 },{ 1, 3 } };
int cctv3[4][2] = { { 0, 3 },{ 0, 1 },{ 1, 2 },{ 2, 3 } };
int cctv4[4][3] = { { 0, 2, 3 },{ 0, 1, 3 },{ 0, 1, 2 },{ 1, 2, 3 } };
int cctv5[4] = { 0, 1, 2, 3 };
int minValue = 99999999;
vector<pair<pair<int, int>, pair<int, int>>> cctv;

void dfs(int idx);
void camera();
int calc();
void copy_arr(int a[8][8], int b[8][8]);

int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
				cctv.push_back(make_pair(make_pair(map[i][j], -1), make_pair(i, j)));
		}
	}

	dfs(0);

	cout << minValue << endl;

	return 0;

}

void dfs(int idx)
{

	if (idx == cctv.size())
	{
		int temp[8][8];
		copy_arr(map, temp);
		camera();
		int res = calc();
		if (res < minValue)
			minValue = res;
		copy_arr(temp, map);

		return;
	}

	cctv[idx].first.second = 0;
	dfs(idx + 1);
	if (cctv[idx].first.first != 5)
	{
		cctv[idx].first.second = 1;
		dfs(idx + 1);
	}
	if (cctv[idx].first.first != 5 && cctv[idx].first.first != 2)
	{
		cctv[idx].first.second = 2;
		dfs(idx + 1);
	}
	if (cctv[idx].first.first != 5 && cctv[idx].first.first != 2)
	{
		cctv[idx].first.second = 3;
		dfs(idx + 1);
	}

}

void camera()
{

	int nx = 0;
	int ny = 0;

	for (int i = 0; i < cctv.size(); i++)
	{
		if (cctv[i].first.first == 1)
		{
			nx = cctv[i].second.first + dx[cctv1[cctv[i].first.second]];
			ny = cctv[i].second.second + dy[cctv1[cctv[i].first.second]];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 6)
			{
				if ((map[nx][ny] >= 1 && map[nx][ny] <= 5) || map[nx][ny] == 7)
				{
					nx += dx[cctv1[cctv[i].first.second]];
					ny += dy[cctv1[cctv[i].first.second]];
					continue;
				}
				map[nx][ny] = 7;
				nx += dx[cctv1[cctv[i].first.second]];
				ny += dy[cctv1[cctv[i].first.second]];
			}
		}

		else if (cctv[i].first.first == 2)
		{
			for (int j = 0; j < 2; j++)
			{
				nx = cctv[i].second.first + dx[cctv2[cctv[i].first.second][j]];
				ny = cctv[i].second.second + dy[cctv2[cctv[i].first.second][j]];
				while (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 6)
				{
					if ((map[nx][ny] >= 1 && map[nx][ny] <= 5) || map[nx][ny] == 7)
					{
						nx += dx[cctv2[cctv[i].first.second][j]];
						ny += dy[cctv2[cctv[i].first.second][j]];
						continue;
					}
					map[nx][ny] = 7;
					nx += dx[cctv2[cctv[i].first.second][j]];
					ny += dy[cctv2[cctv[i].first.second][j]];
				}
			}
		}

		else if (cctv[i].first.first == 3)
		{
			for (int j = 0; j < 2; j++)
			{
				nx = cctv[i].second.first + dx[cctv3[cctv[i].first.second][j]];
				ny = cctv[i].second.second + dy[cctv3[cctv[i].first.second][j]];
				while (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 6)
				{
					if ((map[nx][ny] >= 1 && map[nx][ny] <= 5) || map[nx][ny] == 7)
					{
						nx += dx[cctv3[cctv[i].first.second][j]];
						ny += dy[cctv3[cctv[i].first.second][j]];
						continue;
					}
					map[nx][ny] = 7;
					nx += dx[cctv3[cctv[i].first.second][j]];
					ny += dy[cctv3[cctv[i].first.second][j]];
				}
			}
		}

		else if (cctv[i].first.first == 4)
		{
			for (int j = 0; j < 3; j++)
			{
				nx = cctv[i].second.first + dx[cctv4[cctv[i].first.second][j]];
				ny = cctv[i].second.second + dy[cctv4[cctv[i].first.second][j]];
				while (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 6)
				{
					if ((map[nx][ny] >= 1 && map[nx][ny] <= 5) || map[nx][ny] == 7)
					{
						nx += dx[cctv4[cctv[i].first.second][j]];
						ny += dy[cctv4[cctv[i].first.second][j]];
						continue;
					}
					map[nx][ny] = 7;
					nx += dx[cctv4[cctv[i].first.second][j]];
					ny += dy[cctv4[cctv[i].first.second][j]];
				}
			}
		}

		else if (cctv[i].first.first == 5)
		{
			for (int j = 0; j < 4; j++)
			{
				nx = cctv[i].second.first + dx[j];
				ny = cctv[i].second.second + dy[j];
				while (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 6)
				{
					if ((map[nx][ny] >= 1 && map[nx][ny] <= 5) || map[nx][ny] == 7)
					{
						nx += dx[j];
						ny += dy[j];
						continue;
					}
					map[nx][ny] = 7;
					nx += dx[j];
					ny += dy[j];
				}
			}
		}
	}

}

int calc()
{

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				cnt++;
		}
	}

	return cnt;

}

void copy_arr(int a[8][8], int b[8][8])
{

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			b[i][j] = a[i][j];

}