#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, Testcase;

int N;
int element;
vector<int> v;
vector<int>::iterator iter;

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {

			cin >> element;

			if (i == 0)
				v.push_back(element);

			else {

				if (element > v.back()) {

					v.push_back(element);

				}

				else {

					iter = lower_bound(v.begin(), v.end(), element);
					*iter = element;

				}

			}

		}

		cout << "#" << T + 1 << " " << v.size() << endl;

		v.clear();

	}

	return 0;

}