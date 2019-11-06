// you can use includes, for example:
// #include <algorithm>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int N = A.size();
	int curSum = 0;
	int maxSum = 0;
	int maxVal = -9999999;

	for (int i = 0; i < N; i++)
	{
		curSum = max(0, curSum + A[i]);
		maxSum = max(maxSum, curSum);

		maxVal = max(maxVal, A[i]);
	}

	if (maxVal < 0)
		maxSum = maxVal;

	return maxSum;
}