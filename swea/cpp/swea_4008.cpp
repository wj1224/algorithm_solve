#include <iostream>

using namespace std;

int T, Testcase;

int N;
int num_oper[4];
int num[12];
int minValue = 100000000;
int maxValue = -100000000;

void solve(int idx, int res);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;
		for (int i = 0; i < 4; i++)
			cin >> num_oper[i];
		for (int i = 0; i < N; i++)
			cin >> num[i];

		solve(1, num[0]);

		int res = maxValue - minValue;

		cout << "#" << T + 1 << " " << res << endl;

		minValue = 100000000;
		maxValue = -100000000;
		fill(&num_oper[0], &num_oper[12], 0);

	}

	return 0;

}

void solve(int idx, int res)
{

	if (idx == N)
	{
		if (res > maxValue)
			maxValue = res;
		if (res < minValue)
			minValue = res;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (num_oper[i] != 0)
		{
			num_oper[i]--;
			if (i == 0)
				solve(idx + 1, res + num[idx]);
			else if (i == 1)
				solve(idx + 1, res - num[idx]);
			else if (i == 2)
				solve(idx + 1, res * num[idx]);
			else if (i == 3)
				solve(idx + 1, res / num[idx]);
			num_oper[i]++;
		}
	}

}