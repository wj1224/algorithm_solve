#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int T, Testcase;

int N;
int minValue = 99999999;
int people[10][2];
int ladder[2][3];
int manhat_dist[10][2];
vector<int> v1, v2;

void solve(int idx, int people_idx);
int calc(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;
		int temp;
		int people_idx = 0;
		int ladder_idx = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				if (temp == 1)
				{
					people[people_idx][0] = i;
					people[people_idx][1] = j;
					people_idx++;
				}
				else if (temp != 0 && temp != 1)
				{
					ladder[ladder_idx][0] = i;
					ladder[ladder_idx][1] = j;
					ladder[ladder_idx][2] = temp;
					ladder_idx++;
				}
			}
		}

		for (int i = 0; i < people_idx; i++)
		{
			manhat_dist[i][0] = abs(people[i][0] - ladder[0][0]) + abs(people[i][1] - ladder[0][1]);
			manhat_dist[i][1] = abs(people[i][0] - ladder[1][0]) + abs(people[i][1] - ladder[1][1]);
		}

		solve(0, people_idx);

		cout << "#" << T + 1 << " " << minValue << endl;

		minValue = 99999999;
		fill(&people[0][0], &people[0][0] + sizeof(people), 0);
		fill(&manhat_dist[0][0], &manhat_dist[0][0] + sizeof(manhat_dist), 0);

	}

	return 0;

}

void solve(int idx, int people_idx)
{

	if (v1.size() + v2.size() == people_idx)
	{
		int res = calc();
		if (res < minValue)
			minValue = res;
		return;
	}

	v1.push_back(manhat_dist[idx][0] + 1);
	solve(idx + 1, people_idx);
	v1.pop_back();
	v2.push_back(manhat_dist[idx][1] + 1);
	solve(idx + 1, people_idx);
	v2.pop_back();

}

int calc(void)
{
	vector<int> temp1 = v1;
	vector<int> temp2 = v2;
	int v1_res[10] = { 0, };
	int v2_res[10] = { 0, };
	int v1_idx = 0;
	int v2_idx = 0;

	if (!temp1.empty())
	{
		v1_idx = temp1.size() - 1;
		sort(temp1.begin(), temp1.end());
		for (int i = 0; i < temp1.size(); i++)
			v1_res[i] = (temp1[i] + ladder[0][2]);
		if (temp1.size() > 3)
		{
			for (int i = 3; i < temp1.size(); i++)
			{
				if (temp1[i] < temp1[i - 3] + ladder[0][2])
					v1_res[i] = (temp1[i] + ladder[0][2] + (temp1[i - 3] + ladder[0][2] - temp1[i]));
				else
					v1_res[i] = (temp1[i] + ladder[0][2]);
			}
		}
	}

	if (!temp2.empty())
	{
		v2_idx = temp2.size() - 1;
		sort(temp2.begin(), temp2.end());
		for (int i = 0; i < temp2.size(); i++)
			v2_res[i] = (temp2[i] + ladder[1][2]);
		if (temp2.size() > 3)
		{
			for (int i = 3; i < temp2.size(); i++)
			{
				if (temp2[i] < temp2[i - 3] + ladder[1][2])
					v2_res[i] = (temp2[i] + ladder[1][2] + (temp2[i - 3] + ladder[1][2] - temp2[i]));
				else
					v2_res[i] = (temp2[i] + ladder[1][2]);
			}
		}
	}

	if (v1_res[v1_idx] > v2_res[v2_idx])
		return v1_res[v1_idx];
	else
		return v2_res[v2_idx];

}