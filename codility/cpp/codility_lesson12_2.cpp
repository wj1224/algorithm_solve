// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b);
bool solve(int a, int b);

int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	int res = 0;

	for (int i = 0; i < N; i++)
	{
		if (solve(B[i], A[i]))
			res++;
	}

	return res;
}

int gcd(int a, int b)
{
	int temp;

	if (a % b == 0)
		return b;

	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

bool solve(int a, int b)
{
	int gcd_ab = gcd(a, b);
	int gcd_a = 0;
	int gcd_b = 0;

	while (gcd_a != 1)
	{
		gcd_a = gcd(a, gcd_ab);
		a /= gcd_a;
	}

	while (gcd_b != 1)
	{
		gcd_b = gcd(b, gcd_ab);
		b /= gcd_b;
	}

	if (a == 1 && b == 1)
		return true;
	else
		return false;
}