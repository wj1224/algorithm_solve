#include <iostream>

using namespace std;

int T, Testcase;

int N, M, R, C, L, res;
int map[50][50];
int check[50][50];
int dx1[4] = { 0, 1, 0 ,-1 };
int dy1[4] = { 1, 0, -1, 0 };
int dx2[2] = { 1, -1 };
int dy2[2] = { 0, 0 };
int dx3[2] = { 0, 0 };
int dy3[2] = { 1, -1 };
int dx4[2] = { 0, -1 };
int dy4[2] = { 1, 0 };
int dx5[2] = { 0, 1 };
int dy5[2] = { 1, 0 };
int dx6[2] = { 1, 0 };
int dy6[2] = { 0, -1 };
int dx7[2] = { 0, -1 };
int dy7[2] = { -1, 0 };

void solve(int idx, int x, int y);
int res_cnt(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}

		solve(1, R, C);

		res = res_cnt();

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = 0;
				check[i][j] = 0;
			}
		}

	}

	return 0;

}

void solve(int idx, int x, int y)
{

	check[x][y] = idx;

	if (idx == L)
		return;

	if (map[x][y] == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx1[i];
			int ny = y + dy1[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 2) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 3) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

	else if (map[x][y] == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx2[i];
			int ny = y + dy2[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

	else if (map[x][y] == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx3[i];
			int ny = y + dy3[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

	else if (map[x][y] == 4)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx4[i];
			int ny = y + dy4[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

	else if (map[x][y] == 5)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx5[i];
			int ny = y + dy5[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

	else if (map[x][y] == 6)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx6[i];
			int ny = y + dy6[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

	else if (map[x][y] == 7)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx7[i];
			int ny = y + dy7[i];
			if ((x != nx && nx >= 0 && nx <= N - 1) || (y != ny && ny >= 0 && ny <= M - 1))
			{
				if ((i == 0) && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
				else if ((i == 1) && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6))
				{
					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
						solve(idx + 1, nx, ny);
				}
			}
		}
	}

}

int res_cnt(void)
{

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] != 0)
				cnt++;
		}
	}

	return cnt;

}