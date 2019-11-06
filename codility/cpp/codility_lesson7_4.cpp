// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
	// write your code in C++14 (g++ 6.2.0)
	int N = H.size();
	int res = 0;
	stack<int> s;

	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && H[i] < s.top())
			s.pop();

		if (s.empty() || H[i] > s.top())
		{
			res++;
			s.push(H[i]);
		}
	}

	return res;
}