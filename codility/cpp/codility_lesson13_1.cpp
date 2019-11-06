// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	vector<int> v;
	int maxA = -99999999;
	int maxB = -99999999;

	for (int i = 0; i < N; i++)
	{
		if (A[i] > maxA)
			maxA = A[i];
		if (B[i] > maxB)
			maxB = B[i];
	}

	int* fib = new int[maxA + 2]{ 0, };

	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i < maxA + 2; i++)
	{
		fib[i] = (fib[i - 1] + fib[i - 2]) & ((1 << maxB) - 1);
	}

	for (int i = 0; i < N; i++)
		v.push_back(fib[A[i]] % ((1 << B[i])));

	delete[] fib;

	return v;
}