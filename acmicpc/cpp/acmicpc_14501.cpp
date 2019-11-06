#include <iostream>

using namespace std;

int N;
int T[15];
int P[15];
int maxValue = -9999999;

void dfs(int idx, int res);

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];

	dfs(0, 0);

	cout << maxValue << endl;

	return 0;

}

void dfs(int idx, int res)
{
	if (idx >= N)
	{
		if (res > maxValue)
			maxValue = res;
		return;
	}

	if (idx + T[idx] <= N)
		dfs(idx + T[idx], res + P[idx]);
	dfs(idx + 1, res);
}