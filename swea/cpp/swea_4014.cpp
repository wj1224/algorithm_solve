#include <iostream>

using namespace std;

int T, Testcase;

int N, X;
int map[20][20];
int cnt;

void solve(int start, int dir);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> X;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			solve(i, 1);
			solve(i, -1);
		}

		cout << "#" << T + 1 << " " << cnt << endl;

		fill_n(&map[0][0], 20 * 20, 0);
		cnt = 0;

	}

	return 0;

}

void solve(int start, int dir)
{

	int road[20] = { 0, };
	int ladder[20] = { 0, };
	if (dir == 1) // 가로 복사
	{
		for (int i = 0; i < N; i++)
			road[i] = map[start][i];
	}
	else if (dir == -1) // 세로 복사
	{
		for (int i = 0; i < N; i++)
			road[i] = map[i][start];
	}

	int check = 0;
	int loc = 1;
	while (loc < N)
	{
		check = 0;
		if (road[loc] == road[loc - 1])
			loc++;
		else if (road[loc] == road[loc - 1] + 1)
		{
			if (loc >= X)
			{
				for (int i = loc - X; i < loc; i++)
				{
					if (road[i] == road[loc] - 1 && ladder[i] == 0)
						check = 1;
					else
					{
						check = 0;
						break;
					}
				}
				if (check == 1)
				{
					for (int i = loc - X; i < loc; i++)
						ladder[i] = 1;
					loc++;
				}
				else
					break;
			}
			else
				break;
		}
		else if (road[loc] == road[loc - 1] - 1)
		{
			int temp_loc = loc - 1;
			if (temp_loc + X < N)
			{
				for (int i = temp_loc + 1; i <= temp_loc + X; i++)
				{
					if (road[i] == road[temp_loc] - 1 && ladder[i] == 0)
						check = 1;
					else
					{
						check = 0;
						break;
					}
				}
				if (check == 1)
				{
					for (int i = temp_loc + 1; i <= temp_loc + X; i++)
						ladder[i] = 1;
					loc += X;
				}
				else
					break;
			}
			else
				break;
		}
		else
			break;
	}

	if (loc == N)
		cnt++;

	return;

}