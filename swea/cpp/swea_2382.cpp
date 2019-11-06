#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int T, Testcase;

int N, M, K;
vector<pair<pair<int, int>, pair<int, int>>> v;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

void MoveBug(void);
void CrashBug(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N >> M >> K;

		int temp[4];
		for (int i = 0; i < K; i++)
		{
			cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
			v.push_back({ { temp[0], temp[1] },{ temp[2], temp[3] } });
		}

		for (int i = 0; i < M; i++)
		{
			MoveBug();
			CrashBug();
		}

		int res = 0;
		for (auto it = v.begin(); it < v.end(); it++)
			res += (*it).second.first;

		cout << "#" << T + 1 << " " << res << endl;

		v.clear();

	}

	return 0;

}

void MoveBug(void)
{

	int nx, ny;

	for (auto it = v.begin(); it < v.end(); it++)
	{
		nx = (*it).first.first + dx[(*it).second.second];
		ny = (*it).first.second + dy[(*it).second.second];
		(*it).first.first = nx;
		(*it).first.second = ny;

		if (nx == 0)
		{
			(*it).second.first /= 2;
			(*it).second.second = 2;
		}
		else if (nx == N - 1)
		{
			(*it).second.first /= 2;
			(*it).second.second = 1;
		}
		else if (ny == 0)
		{
			(*it).second.first /= 2;
			(*it).second.second = 4;
		}
		else if (ny == N - 1)
		{
			(*it).second.first /= 2;
			(*it).second.second = 3;
		}
	}

}

void CrashBug(void)
{

	vector<pair<pair<int, int>, pair<int, int>>>::iterator it;
	vector<pair<pair<int, int>, pair<int, int>>>::iterator it2;
	int idx = 0;

	sort(v.begin(), v.end(), greater<pair<pair<int, int>, pair<int, int>>>());

	while (1)
	{
		if (idx >= v.size() - 1)
			break;

		it = v.begin() + idx;
		it2 = v.begin() + idx + 1;

		if ((*it).first.first == (*it2).first.first && (*it).first.second == (*it2).first.second)
		{
			(*it).second.first += (*it2).second.first;
			v.erase(it2);
		}
		else
			idx++;
	}

}