#include <iostream>
#include <vector>

using namespace std;

int T, Testcase;

int N, M, C;
int map[10][10];
int Amax, Bmax, maxValue;
vector<int> A;
vector<int> B;

void solve(int hei, int wei);
void calcA(int idx, int sum, int profit);
void calcB(int idx, int sum, int profit);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> M >> C;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		solve(0, 0);

		cout << "#" << T + 1 << " " << maxValue << endl;

		maxValue = 0;
		A.clear();
		B.clear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
			}
		}

	}

	return 0;

}

void solve(int hei, int wei)
{

	if (A.empty())
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j + M <= N; j++)
			{
				for (int k = 0; k < M; k++)
					A.push_back(map[i][j + k]);
				if (j + M - 1 + M >= N)
					solve(i + 1, 0);
				else
					solve(i, j + M);
				for (int k = 0; k < M; k++)
					A.pop_back();
			}
		}
	}

	if (B.empty())
	{
		int wei_temp = wei;
		for (int m = hei; m < N; m++)
		{
			for (int n = wei_temp; n + M <= N; n++)
			{
				for (int o = 0; o < M; o++)
					B.push_back(map[m][n + o]);

				if (!A.empty() && !B.empty())
				{
					calcA(0, 0, 0);
					calcB(0, 0, 0);
					int res = Amax + Bmax;
					if (res > maxValue)
						maxValue = res;
					Amax = 0;
					Bmax = 0;
				}

				for (int o = 0; o < M; o++)
					B.pop_back();

				if (n + M == N)
					wei_temp = 0;
			}
		}
	}

}

void calcA(int idx, int sum, int profit)
{

	if (sum > C)
	{
		return;
	}

	if (idx == M)
	{
		if (profit > Amax)
			Amax = profit;
		return;
	}

	calcA(idx + 1, sum + A[idx], profit + (A[idx] * A[idx]));
	calcA(idx + 1, sum, profit);

}

void calcB(int idx, int sum, int profit)
{

	if (sum > C)
	{
		return;
	}

	if (idx == M)
	{
		if (profit > Bmax)
			Bmax = profit;
		return;
	}

	calcB(idx + 1, sum + B[idx], profit + (B[idx] * B[idx]));
	calcB(idx + 1, sum, profit);

}