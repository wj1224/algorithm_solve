// you can use includes, for example:
// #include <algorithm>
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int dp[100001];

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	memset(dp, -10001, sizeof(dp));
	dp[0] = A[0];

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (i + j >= N)
				break;
			if (dp[i + j] < dp[i] + A[i + j])
				dp[i + j] = dp[i] + A[i + j];
		}
	}

	return dp[N - 1];
}