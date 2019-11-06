#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, Testcase;

vector<int> v1, v2;

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{
		int N, K;
		cin >> N >> K;

		int temp;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			v1.push_back(temp);
		}
		sort(v1.begin(), v1.end());

		for (int i = 0; i < N - 1; i++)
			v2.push_back(v1[i + 1] - v1[i]);

		sort(v2.begin(), v2.end());

		int res = 0;

		for (int i = 0; i < N - K; i++)
			res += v2[i];

		cout << "#" << T + 1 << " " << res << endl;

		v1.clear();
		v2.clear();

	}

	return 0;

}