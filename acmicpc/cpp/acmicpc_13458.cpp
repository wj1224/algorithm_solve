#include <iostream>

using namespace std;

long long int N, B, C, res;
long long int A[1000000];

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		if (A[i] - B >= 0)
			A[i] -= B;
		else
			A[i] = 0;
		if (A[i] % C == 0)
			res += ((A[i] / C) + 1);
		else if (A[i] % C != 0)
			res += ((A[i] / C) + 2);
	}

	cout << res << endl;

	return 0;

}