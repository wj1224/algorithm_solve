#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[6] = { 0, };
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

void move(int num);

int main()
{

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int oper;
	for (int i = 0; i < K; i++)
	{
		cin >> oper;
		x += dx[oper];
		y += dy[oper];
		if (x >= 0 && x < N && y >= 0 && y < M)
		{
			move(oper);
			if (map[x][y] == 0)
				map[x][y] = dice[5];
			else
			{
				dice[5] = map[x][y];
				map[x][y] = 0;
			}
			cout << dice[0] << endl;
		}
		else
		{
			x -= dx[oper];
			y -= dy[oper];
		}
	}

	return 0;

}

void move(int num)
{

	int temp1;
	int temp2;

	if (num == 1)
	{
		temp1 = dice[0];
		temp2 = dice[2];
		dice[0] = dice[3];
		dice[2] = temp1;
		dice[3] = dice[5];
		dice[5] = temp2;
	}

	else if (num == 2)
	{
		temp1 = dice[0];
		temp2 = dice[3];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[3] = temp1;
		dice[5] = temp2;
	}

	else if (num == 3)
	{
		temp1 = dice[0];
		temp2 = dice[1];
		dice[0] = dice[4];
		dice[1] = temp1;
		dice[4] = dice[5];
		dice[5] = temp2;
	}

	else
	{
		temp1 = dice[0];
		temp2 = dice[4];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[4] = temp1;
		dice[5] = temp2;
	}

}