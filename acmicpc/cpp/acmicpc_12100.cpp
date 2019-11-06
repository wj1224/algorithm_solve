#include <iostream>
#include <queue>

using namespace std;

int N;
int map[20][20];
int maxValue;

void move(int dir);
void calc(void);
void copy_arr(int a[20][20], int b[20][20]);
void solve(int idx);

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	solve(0);

	cout << maxValue << endl;

	return 0;

}

void move(int dir)
{

	queue<int> q;

	if (dir == 0) // 오른쪽
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (map[i][j] != 0)
					q.push(map[i][j]);
				map[i][j] = 0;
			}
			for (int j = N - 1; j >= 0; j--)
			{
				if (q.empty())
					break;
				map[i][j] = q.front();
				q.pop();
				if (!q.empty())
				{
					if (q.front() == map[i][j])
					{
						map[i][j] = 2 * map[i][j];
						q.pop();
					}
				}
			}
		}
	}

	else if (dir == 1) // 왼쪽
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != 0)
					q.push(map[i][j]);
				map[i][j] = 0;
			}
			for (int j = 0; j < N; j++)
			{
				if (q.empty())
					break;
				map[i][j] = q.front();
				q.pop();
				if (!q.empty())
				{
					if (q.front() == map[i][j])
					{
						map[i][j] = 2 * map[i][j];
						q.pop();
					}
				}
			}
		}
	}

	else if (dir == 2) // 아래쪽
	{
		for (int j = 0; j < N; j++)
		{
			for (int i = N - 1; i >= 0; i--)
			{
				if (map[i][j] != 0)
					q.push(map[i][j]);
				map[i][j] = 0;
			}
			for (int i = N - 1; i >= 0; i--)
			{
				if (q.empty())
					break;
				map[i][j] = q.front();
				q.pop();
				if (!q.empty())
				{
					if (q.front() == map[i][j])
					{
						map[i][j] = 2 * map[i][j];
						q.pop();
					}
				}
			}
		}
	}

	else if (dir == 3) // 위쪽
	{
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (map[i][j] != 0)
					q.push(map[i][j]);
				map[i][j] = 0;
			}
			for (int i = 0; i < N; i++)
			{
				if (q.empty())
					break;
				map[i][j] = q.front();
				q.pop();
				if (!q.empty())
				{
					if (q.front() == map[i][j])
					{
						map[i][j] = 2 * map[i][j];
						q.pop();
					}
				}
			}
		}
	}

}

void calc(void)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > maxValue)
				maxValue = map[i][j];
		}
	}

}

void copy_arr(int a[20][20], int b[20][20])
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[i][j];
		}
	}

}

void solve(int idx)
{

	if (idx == 5)
	{
		calc();
		return;
	}

	int temp[20][20];
	copy_arr(map, temp);
	move(0);
	solve(idx + 1);
	copy_arr(temp, map);
	move(1);
	solve(idx + 1);
	copy_arr(temp, map);
	move(2);
	solve(idx + 1);
	copy_arr(temp, map);
	move(3);
	solve(idx + 1);
	copy_arr(temp, map);

}