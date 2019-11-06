// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	stack<int> s;
	int N = A.size();
	int res = 0;

	for (int i = 0; i < N; i++)
	{
		if (B[i] == 0)
		{
			if (s.empty())
				res++;
			else
			{
				while (!s.empty() && s.top() < A[i])
					s.pop();
				if (s.empty())
					res++;
			}
		}
		else if (B[i] == 1)
		{
			s.push(A[i]);
		}
	}

	if (s.empty())
		return res;
	else
		return res + s.size();
}