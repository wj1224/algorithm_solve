#include <iostream>

using namespace std;

int T, Testcase;

int check[1000001];
int N, temp;

int main() {

	for (N = 2; N <= 1000000; N++) {

		if (check[N] == 0) {

			cout << N << " ";

			temp = N;

			while (temp + N <= 1000000) {

				temp += N;
				check[temp] = 1;

			}

		}

	}

	return 0;

}