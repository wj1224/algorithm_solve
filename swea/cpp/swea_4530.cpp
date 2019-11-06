#include <iostream>

using namespace std;

int T, Testcase;

long long int numA;
long long int numB;
long long int DP[15];
long long int res;

long long int calc(long long int num);

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> numA >> numB;

		DP[0] = 1;
		for (int i = 1; i < 15; i++)
			DP[i] = 9 * DP[i - 1];

		if (numA < 0 && numB < 0) {
			numA = -numA;
			numB = -numB;
		}

		if (numA > 0 && numB > 0 && numA > numB)
			res = calc(numA) - calc(numB);
		else if (numA > 0 && numB > 0 && numB > numA)
			res = calc(numB) - calc(numA);
		else if (numA > 0 && numB < 0)
			res = calc(numA) + calc(-numB) - 1;
		else if (numA < 0 && numB > 0)
			res = calc(-numA) + calc(numB) - 1;

		cout << "#" << T + 1 << " " << res << endl;

	}

	return 0;

}

long long int calc(long long int num) {

	long long int val = 0;
	long long int remain = 0;
	int i = 0;

	while (num != 0) {

		remain = num % 10;

		if (remain < 4)
			val += (remain * DP[i++]);
		else
			val += ((remain - 1) * DP[i++]);

		num /= 10;

	}

	return val;

}