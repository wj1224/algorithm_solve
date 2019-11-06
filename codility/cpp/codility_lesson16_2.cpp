// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();

	if (A.empty())
		return 0;

	int res = 1;
	int end = B[0];

	for (int i = 1; i < N; i++)
	{
		if (A[i] > end)
		{
			res++;
			end = B[i];
		}
	}

	return res;
}