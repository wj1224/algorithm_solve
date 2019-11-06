// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int res = 0;
	int cur_sum = 0;

	for (int i = 0; i < A.size(); i++)
	{
		cur_sum += A[i];
		if (cur_sum >= K)
		{
			res++;
			cur_sum = 0;
		}
	}

	return res;
}