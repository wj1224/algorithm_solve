#include <iostream>

using namespace std;

int N, M;
int minValue = 11;
int check;
char map[10][10];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void move(int dir, int num);
void copy_arr(char a[10][10], char b[10][10]);
void solve(int idx);

int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	solve(0);
	if (minValue == 11)
		minValue = -1;

	cout << minValue << endl;

	return 0;

}

void move(int dir, int num)
{
	if (num >= minValue)
		return;

	int red_nx = 0, red_ny = 0, blue_nx = 0, blue_ny = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'R')
			{
				red_nx = i;
				red_ny = j;
			}
			if (map[i][j] == 'B')
			{
				blue_nx = i;
				blue_ny = j;
			}
		}
	}

	if ((red_nx == 0 && red_ny == 0) || (blue_nx == 0 && blue_ny == 0))
		return;

	while (1)
	{
		red_nx += dx[dir];
		red_ny += dy[dir];
		blue_nx += dx[dir];
		blue_ny += dy[dir];
		if ((map[red_nx][red_ny] == 'O'))
		{
			map[red_nx - dx[dir]][red_ny - dy[dir]] = '.';
			while (1)
			{
				if (map[blue_nx][blue_ny] == 'O')
				{
					check = 1;
					return;
				}
				else if (map[blue_nx][blue_ny] == '#')
				{
					minValue = num;
					return;
				}
				blue_nx += dx[dir];
				blue_ny += dy[dir];
			}
		}
		else if ((map[blue_nx][blue_ny] == 'O'))
		{
			check = 1;
			return;
		}

		else if ((map[red_nx][red_ny] == '#' || map[red_nx][red_ny] == 'B') && (map[blue_nx][blue_ny] == '#' || map[blue_nx][blue_ny] == 'R'))
		{
			map[red_nx - dx[dir]][red_ny - dy[dir]] = 'R';
			map[blue_nx - dx[dir]][blue_ny - dy[dir]] = 'B';
			return;
		}
		else if (map[red_nx][red_ny] == '#' || map[red_nx][red_ny] == 'B')
		{
			red_nx -= dx[dir];
			red_ny -= dy[dir];
			map[red_nx][red_ny] = 'R';
			map[blue_nx - dx[dir]][blue_ny - dy[dir]] = '.';
			map[blue_nx][blue_ny] = 'B';
		}
		else if (map[blue_nx][blue_ny] == '#' || map[blue_nx][blue_ny] == 'R')
		{
			blue_nx -= dx[dir];
			blue_ny -= dy[dir];
			map[blue_nx][blue_ny] = 'B';
			map[red_nx - dx[dir]][red_ny - dy[dir]] = '.';
			map[red_nx][red_ny] = 'R';
		}
		else
		{
			map[red_nx - dx[dir]][red_ny - dy[dir]] = '.';
			map[blue_nx - dx[dir]][blue_ny - dy[dir]] = '.';
			map[red_nx][red_ny] = 'R';
			map[blue_nx][blue_ny] = 'B';
		}
	}

}

void copy_arr(char a[10][10], char b[10][10])
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			b[i][j] = a[i][j];
		}
	}

}

void solve(int idx)
{

	if (idx >= minValue - 1)
		return;
	if (check == 1)
		return;

	char temp[10][10];
	copy_arr(map, temp);
	move(0, idx + 1);
	solve(idx + 1);
	check = 0;
	copy_arr(temp, map);
	move(1, idx + 1);
	solve(idx + 1);
	check = 0;
	copy_arr(temp, map);
	move(2, idx + 1);
	solve(idx + 1);
	check = 0;
	copy_arr(temp, map);
	move(3, idx + 1);
	solve(idx + 1);
	check = 0;
	copy_arr(temp, map);

}