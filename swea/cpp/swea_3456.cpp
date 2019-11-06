#include <iostream>

using namespace std;

int T, Testcase;

int length[3];

int main() {

	cin >> Testcase;

	for (T = 0; T < Testcase; T++) {

		for (int i = 0; i < 3; i++)
			cin >> length[i];

		if (length[0] == length[1])
			cout << "#" << T + 1 << " " << length[2] << endl;
		else if (length[0] == length[2])
			cout << "#" << T + 1 << " " << length[1] << endl;
		else if (length[1] == length[2])
			cout << "#" << T + 1 << " " << length[0] << endl;

	}

	return 0;

}