// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N, int M) {
	// write your code in C++14 (g++ 6.2.0)
	if (N % M == 0)
		return N / M;

	int a = N;
	int b = M;
	int temp;

	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return N / a;

}