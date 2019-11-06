#include <iostream>

using namespace std;

int N;
int num[11];
int num_oper[4];
int maxValue = -1000000000;
int minValue = 1000000000;

void dfs(int idx, int res);

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> num_oper[i];

	dfs(0, num[0]);

	cout << maxValue << endl << minValue << endl;

	return 0;

}

void dfs(int idx, int res)
{

	if (idx == N - 1)
	{
		if (res < minValue)
			minValue = res;
		if (res > maxValue)
			maxValue = res;
		return;
	}

	if (num_oper[0] != 0)
	{
		num_oper[0]--;
		dfs(idx + 1, res + num[idx + 1]);
		num_oper[0]++;
	}
	if (num_oper[1] != 0)
	{
		num_oper[1]--;
		dfs(idx + 1, res - num[idx + 1]);
		num_oper[1]++;
	}
	if (num_oper[2] != 0)
	{
		num_oper[2]--;
		dfs(idx + 1, res * num[idx + 1]);
		num_oper[2]++;
	}
	if (num_oper[3] != 0)
	{
		num_oper[3]--;
		dfs(idx + 1, res / num[idx + 1]);
		num_oper[3]++;
	}

}