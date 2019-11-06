// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int> letters;
	vector<int> digits;
	vector<int> temp;
	int N = S.size();
	int maxValue = -1;

	for (int i = 0; i < N; i++)
	{
		if ((int)S[i] == 32)
		{
			if (letters.size() % 2 == 0 && digits.size() % 2 == 1 && temp.empty())
			{
				int num = letters.size() + digits.size();
				if (num > maxValue)
					maxValue = num;
			}
			letters.clear();
			digits.clear();
			temp.clear();
		}

		if ((int)S[i] >= 65 && (int)S[i] <= 90)
			letters.push_back((int)S[i]);
		else if ((int)S[i] >= 97 && (int)S[i] <= 122)
			letters.push_back((int)S[i]);
		else if ((int)S[i] >= 48 && (int)S[i] <= 57)
			digits.push_back((int)S[i]);
		else if ((int)S[i] != 32)
			temp.push_back((int)S[i]);
	}

	if (letters.size() % 2 == 0 && digits.size() % 2 == 1 && temp.empty())
	{
		int num = letters.size() + digits.size();
		if (num > maxValue)
			maxValue = num;
	}
	letters.clear();
	digits.clear();
	temp.clear();

	return maxValue;
}