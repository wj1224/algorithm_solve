// you can use includes, for example:
// #include <algorithm>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	if (A.empty() || A.size() == 1)
		return 0;

	int N = A.size();
	int minVal = A[0];
	int maxProfit = 0;

	for (int i = 1; i < N; i++)
	{
		maxProfit = max(maxProfit, A[i] - minVal);
		minVal = min(minVal, A[i]);
	}

	return maxProfit;
}