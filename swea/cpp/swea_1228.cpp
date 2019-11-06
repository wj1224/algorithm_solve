#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, Testcase;

int CodeLength, NumOper;
int temp, temp2;
char operation;
int location;
int NumCode;

vector<int> v;
vector<int>::iterator iter;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> CodeLength;

		for (int i = 0; i < CodeLength; i++) {

			cin >> temp;
			v.push_back(temp);

		}

		cin >> NumOper;

		for (int i = 0; i < NumOper; i++) {

			cin >> operation >> location >> NumCode;

			iter = v.begin() + location;

			for (int j = 0; j < NumCode; j++) {
				cin >> temp2;
				iter = v.insert(iter, temp2);
				iter++;
			}

		}

		cout << "#" << T + 1;
		for (int i = 0; i < 10; i++) {
			cout << " " << v[i];
		}
		cout << endl;

		v.clear();

	}

	return 0;

}