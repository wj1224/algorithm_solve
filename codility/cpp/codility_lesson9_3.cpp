// you can use includes, for example:
// #include <algorithm>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	int maxSum = 0;
	int* LtoR = new int[N] {0, };
	int* RtoL = new int[N] {0, };

	for (int i = 1; i < N; i++)
		LtoR[i] = max(0, LtoR[i - 1] + A[i]);

	for (int i = N - 2; i >= 0; i--)
		RtoL[i] = max(0, RtoL[i + 1] + A[i]);

	for (int i = 1; i < N - 1; i++)
		maxSum = max(maxSum, LtoR[i - 1] + RtoL[i + 1]);

	delete[] LtoR;
	delete[] RtoL;

	return maxSum;
}