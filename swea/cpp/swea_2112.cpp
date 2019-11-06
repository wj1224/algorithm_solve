#include <iostream>

using namespace std;

int T, Testcase;

int D, W, K;
int map[13][20];
int minValue;
int visit[13];

void solve(int idx, int depth);
int check(void);
void conversion(int type, int hei);
void copyarr(int a[20], int b[20]);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
			}
		}

		minValue = D;
		solve(0, 0);

		cout << "#" << T + 1 << " " << minValue << endl;

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				map[i][j] = 0;
			}
			visit[i] = 0;
		}

	}

	return 0;

}

void solve(int idx, int depth)
{

	if (idx >= minValue)
		return;

	if (depth >= D) {
		int sign = check();
		if (sign == 0)
		{
			if (idx < minValue)
			{
				minValue = idx;
			}
		}
		return;
	}

	if (visit[depth] == 0)
	{
		visit[depth] = 1;

		solve(idx, depth + 1);

		int temp[20];

		copyarr(temp, map[depth]);
		conversion(0, depth);
		solve(idx + 1, depth + 1);
		copyarr(map[depth], temp);

		copyarr(temp, map[depth]);
		conversion(1, depth);
		solve(idx + 1, depth + 1);
		copyarr(map[depth], temp);

		visit[depth] = 0;
	}

}

int check(void)
{

	int check_cons[20] = { 0, };
	for (int wei = 0; wei < W; wei++)
	{
		for (int hei = 0; hei < D - K + 1; hei++)
		{
			int k = 1;
			int temp = 0;
			while (hei + k - 1 < hei + K - 1)
			{
				if (map[hei][wei] == map[hei + k][wei])
					temp++;
				else
					break;
				k++;
			}

			if (temp == K - 1)
			{
				check_cons[wei] = 1;
				break;
			}
		}
	}

	int cnt = 0;
	for (int wei = 0; wei < W; wei++)
	{
		if (check_cons[wei] == 1)
			cnt++;
	}

	if (cnt == W)
		return 0;
	else
		return 1;

}

void conversion(int type, int hei)
{

	for (int wei = 0; wei < W; wei++)
		map[hei][wei] = type;

}

void copyarr(int a[20], int b[20])
{

	for (int wei = 0; wei < W; wei++)
		a[wei] = b[wei];

}