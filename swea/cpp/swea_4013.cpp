#include <iostream>

using namespace std;

int T, Testcase;

int K;
int magnet[4][8];
int order[4];
int dir[4];

void turn_magnet(int idx, int dir);
void get_order(void);
void get_dir(int idx);
int get_score(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> K;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> magnet[i][j];
			}
		}

		for (int i = 0; i < K; i++)
		{
			cin >> order[0];
			order[0]--;
			cin >> dir[order[0]];
			get_order();

			for (int j = 0; j < 4; j++)
			{
				get_dir(order[j]);
			}
			for (int j = 0; j < 4; j++)
			{
				turn_magnet(order[j], dir[order[j]]);
			}

			for (int j = 0; j < 4; j++)
			{
				order[j] = 0;
				dir[j] = 0;
			}
		}

		int res = get_score();

		cout << "#" << T + 1 << " " << res << endl;

	}

	return 0;

}

void turn_magnet(int idx, int dir)
{

	if (dir == 0)
		return;

	int temp[8];

	if (dir == 1)
	{
		temp[0] = magnet[idx][7];
		for (int i = 0; i < 7; i++)
			temp[i + 1] = magnet[idx][i];
	}
	else if (dir == -1)
	{
		temp[7] = magnet[idx][0];
		for (int i = 1; i < 8; i++)
			temp[i - 1] = magnet[idx][i];
	}
	for (int i = 0; i < 8; i++)
		magnet[idx][i] = temp[i];

	return;

}

void get_order(void)
{

	if (order[0] == 0)
	{
		order[1] = 1;
		order[2] = 2;
		order[3] = 3;
	}
	else if (order[0] == 1)
	{
		order[1] = 0;
		order[2] = 2;
		order[3] = 3;
	}
	else if (order[0] == 2)
	{
		order[1] = 3;
		order[2] = 1;
		order[3] = 0;
	}
	else if (order[0] == 3)
	{
		order[1] = 2;
		order[2] = 1;
		order[3] = 0;
	}

	return;

}

void get_dir(int idx)
{
	if (dir[idx] != 0)
		return;

	if (idx == 0)
	{
		if (dir[idx + 1] != 0 && magnet[idx][2] != magnet[idx + 1][6])
		{
			if (dir[idx + 1] == 1)
				dir[idx] = -1;
			else
				dir[idx] = 1;
		}
		else
			dir[idx] = 0;
	}

	else if (idx == 1 || idx == 2)
	{
		if (dir[idx - 1] != 0 && magnet[idx][6] != magnet[idx - 1][2])
		{
			if (dir[idx - 1] == 1)
				dir[idx] = -1;
			else
				dir[idx] = 1;
		}
		else if (dir[idx + 1] != 0 && magnet[idx][2] != magnet[idx + 1][6])
		{
			if (dir[idx + 1] == 1)
				dir[idx] = -1;
			else
				dir[idx] = 1;
		}
		else
			dir[idx] = 0;
	}

	else if (idx == 3)
	{
		if (dir[idx - 1] != 0 && magnet[idx][6] != magnet[idx - 1][2])
		{
			if (dir[idx - 1] == 1)
				dir[idx] = -1;
			else
				dir[idx] = 1;
		}
		else
			dir[idx] = 0;
	}

}

int get_score(void)
{

	int res = 0;

	if (magnet[0][0] == 1)
		res += 1;
	if (magnet[1][0] == 1)
		res += 2;
	if (magnet[2][0] == 1)
		res += 4;
	if (magnet[3][0] == 1)
		res += 8;

	return res;

}