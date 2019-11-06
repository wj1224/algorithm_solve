#include <iostream>
#include <string>
#include <vector>

using namespace std;

int K, ans;
int info[4];
vector<int> v[4];

void make_info(int num, int dir);
void turn_wheel(int num, int dir);

int main()
{

	for (int i = 0; i < 4; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++)
		{
			v[i].push_back(temp[j] - '0');
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		make_info(temp1, temp2);
		for (int j = 0; j < 4; j++)
			turn_wheel(j, info[j]);
	}

	if (v[0][0] == 1)
		ans++;
	if (v[1][0] == 1)
		ans += 2;
	if (v[2][0] == 1)
		ans += 4;
	if (v[3][0] == 1)
		ans += 8;

	cout << ans << endl;

	return 0;

}

void make_info(int num, int dir)
{

	if (num == 1)
	{
		if (dir == 1)
		{
			info[0] = 1;
			if (v[0][2] != v[1][6])
				info[1] = -1;
			else
				info[1] = 0;
			if (info[1] == -1 && v[1][2] != v[2][6])
				info[2] = 1;
			else
				info[2] = 0;
			if (info[2] == 1 && v[2][2] != v[3][6])
				info[3] = -1;
			else
				info[3] = 0;
		}
		else if (dir == -1)
		{
			info[0] = -1;
			if (v[0][2] != v[1][6])
				info[1] = 1;
			else
				info[1] = 0;
			if (info[1] == 1 && v[1][2] != v[2][6])
				info[2] = -1;
			else
				info[2] = 0;
			if (info[2] == -1 && v[2][2] != v[3][6])
				info[3] = 1;
			else
				info[3] = 0;
		}
	}

	else if (num == 2)
	{
		if (dir == 1)
		{
			info[1] = 1;
			if (v[0][2] != v[1][6])
				info[0] = -1;
			else
				info[0] = 0;
			if (v[1][2] != v[2][6])
				info[2] = -1;
			else
				info[2] = 0;
			if (info[2] == -1 && v[2][2] != v[3][6])
				info[3] = 1;
			else
				info[3] = 0;
		}
		else if (dir == -1)
		{
			info[1] = -1;
			if (v[0][2] != v[1][6])
				info[0] = 1;
			else
				info[0] = 0;
			if (v[1][2] != v[2][6])
				info[2] = 1;
			else
				info[2] = 0;
			if (info[2] == 1 && v[2][2] != v[3][6])
				info[3] = -1;
			else
				info[3] = 0;
		}
	}

	else if (num == 3)
	{
		if (dir == 1)
		{
			info[2] = 1;
			if (v[2][2] != v[3][6])
				info[3] = -1;
			else
				info[3] = 0;
			if (v[1][2] != v[2][6])
				info[1] = -1;
			else
				info[1] = 0;
			if (info[1] == -1 && v[0][2] != v[1][6])
				info[0] = 1;
			else
				info[0] = 0;
		}
		else if (dir == -1)
		{
			info[2] = -1;
			if (v[2][2] != v[3][6])
				info[3] = 1;
			else
				info[3] = 0;
			if (v[1][2] != v[2][6])
				info[1] = 1;
			else
				info[1] = 0;
			if (info[1] == 1 && v[0][2] != v[1][6])
				info[0] = -1;
			else
				info[0] = 0;
		}
	}

	if (num == 4)
	{
		if (dir == 1)
		{
			info[3] = 1;
			if (v[2][2] != v[3][6])
				info[2] = -1;
			else
				info[2] = 0;
			if (info[2] == -1 && v[1][2] != v[2][6])
				info[1] = 1;
			else
				info[1] = 0;
			if (info[1] == 1 && v[0][2] != v[1][6])
				info[0] = -1;
			else
				info[0] = 0;
		}
		else if (dir == -1)
		{
			info[3] = -1;
			if (v[2][2] != v[3][6])
				info[2] = 1;
			else
				info[2] = 0;
			if (info[2] == 1 && v[1][2] != v[2][6])
				info[1] = -1;
			else
				info[1] = 0;
			if (info[1] == -1 && v[0][2] != v[1][6])
				info[0] = 1;
			else
				info[0] = 0;
		}
	}

}

void turn_wheel(int num, int dir)
{

	if (dir == 1)
	{
		int temp = v[num][7];
		v[num].pop_back();
		v[num].insert(v[num].begin(), temp);
	}

	else if (dir == -1)
	{
		int temp = v[num][0];
		v[num].erase(v[num].begin());
		v[num].push_back(temp);
	}

	else if (dir == 0)
		return;

}