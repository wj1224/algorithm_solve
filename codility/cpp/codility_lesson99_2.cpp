// you can use includes, for example:
// #include <algorithm>
#include <string>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	if (S.empty())
		return -1;
	else if (S.size() == 1)
		return 0;
	else if (S.size() % 2 == 0)
		return -1;

	int k = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (i == S.size() / 2)
			break;
		if (S[i] == S[S.size() - 1 - i])
		{
			k++;
			continue;
		}
		return -1;
	}

	return k;

}