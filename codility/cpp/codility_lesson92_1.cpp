// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int P, int C) {
	// write your code in C++14 (g++ 6.2.0)
	if (P == 1)
		return 0;
	if (P / 2 >= C)
		return C;
	else
		return P / 2;
}