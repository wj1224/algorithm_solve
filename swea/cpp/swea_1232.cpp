#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, Testcase;

int N, res;
vector<vector<pair<string, pair<int, int>>>> v(1001);

int solve(int node);

int main()
{

	Testcase = 10;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;

		int node, LC, RC;
		string temp;

		for (int i = 0; i < N; i++)
		{

			cin >> node >> temp;

			if (temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/')
			{
				cin >> LC >> RC;
				v[node].push_back({ temp,{ LC, RC } });
			}
			else
				v[node].push_back({ temp,{ -1, -1 } });

		}

		res = solve(1);

		cout << "#" << T + 1 << " " << res << endl;

		for (int i = 1; i <= N; i++)
			v[i].clear();

	}

	return 0;

}

int solve(int node)
{
	auto it = v[node].begin();

	if ((*it).second.first == -1 && (*it).second.second == -1)
		return atoi((*it).first.c_str());
	else if ((*it).first[0] == '+')
		return (solve((*it).second.first) + solve((*it).second.second));
	else if ((*it).first[0] == '-')
		return (solve((*it).second.first) - solve((*it).second.second));
	else if ((*it).first[0] == '*')
		return (solve((*it).second.first) * solve((*it).second.second));
	else if ((*it).first[0] == '/')
		return (solve((*it).second.first) / solve((*it).second.second));

}