#include <iostream>
#include <vector>

using namespace std;

int T, Testcase;

int N;
int synergy[16][16];
vector<int> A, B;
int minValue = 9999999999;

void solve(int idx);
int calc(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> synergy[i][j];
			}
		}

		solve(0);

		cout << "#" << T + 1 << " " << minValue << endl;

		minValue = 9999999999;
		fill_n(&synergy[0][0], 16 * 16, 0);
		A.clear();
		B.clear();

	}

	return 0;

}

void solve(int idx)
{

	if (idx == N)
	{
		int res = calc();
		if (res < minValue)
			minValue = res;
		return;
	}

	if (A.size() < N / 2)
	{
		A.push_back(idx);
		solve(idx + 1);
		A.pop_back();
	}
	if (B.size() < N / 2)
	{
		B.push_back(idx);
		solve(idx + 1);
		B.pop_back();
	}

}

int calc(void)
{

	int A_sum = 0;
	int B_sum = 0;

	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			if (i == j)
				continue;
			else
			{
				A_sum += synergy[A[i]][A[j]];
				B_sum += synergy[B[i]][B[j]];
			}
		}
	}

	return abs(A_sum - B_sum);

}