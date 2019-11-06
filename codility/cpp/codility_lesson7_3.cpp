// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	if (S.empty())
		return 1;

	stack<char> s;
	int N = S.size();

	for (int i = 0; i < N; i++)
	{
		if (S[i] == '(')
			s.push(S[i]);
		else
		{
			if (s.empty())
				return 0;
			else
				s.pop();
		}
	}

	if (s.empty())
		return 1;
	else
		return 0;
}