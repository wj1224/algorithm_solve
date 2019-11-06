#include <iostream>
#include <vector>

using namespace std;

int T, Testcase;

int N, res;
vector<pair<pair<int, int>, pair<int, int>>> v;
int map[4001][4001];

void MoveAtom(void);
void CrushAtom(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;
		int temp[4];
		for (int i = 0; i < N; i++)
		{
			cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
			v.push_back({ { (temp[0] + 1000) * 2, (temp[1] + 1000) * 2 },{ temp[2], temp[3] } });
		}

		for (int i = 0; i < 4000; i++)
		{
			if (v.empty())
				break;
			MoveAtom();
			CrushAtom();
		}

		cout << "#" << T + 1 << " " << res << endl;

		v.clear();
		res = 0;

	}

	return 0;

}

void MoveAtom(void)
{

	int i = 0;
	int size = v.size();

	while (i < size)
	{
		if (v[i].second.first == 0)
			v[i].first.second++;
		else if (v[i].second.first == 1)
			v[i].first.second--;
		else if (v[i].second.first == 2)
			v[i].first.first--;
		else if (v[i].second.first == 3)
			v[i].first.first++;

		if (v[i].first.first < 0 || v[i].first.second < 0 || v[i].first.first > 4000 || v[i].first.second > 4000 || v[i].second.first == 4)
		{
			if (v[i].second.first == 4)
				res += v[i].second.second;
			auto it = v.begin() + i;
			v.erase(it);
			size = v.size();
			i--;
		}
		i++;
	}

}

void CrushAtom(void)
{

	int idx_check[1001] = { 0, };
	int temp[1001] = { 0, };
	int k = 0;
	int l = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (map[v[i].first.first][v[i].first.second] == 0)
		{
			map[v[i].first.first][v[i].first.second] = i + 1;
			temp[l] = i;
			l++;
		}
		else
		{
			if (idx_check[map[v[i].first.first][v[i].first.second]] == 0)
			{
				v[map[v[i].first.first][v[i].first.second] - 1].second.first = 4;
				idx_check[map[v[i].first.first][v[i].first.second]] = 1;
				k++;
			}
			v[i].second.first = 4;
			idx_check[i + 1] = 1;
			k++;
		}
	}
	for (int i = 0; i < l; i++)
		map[v[temp[i]].first.first][v[temp[i]].first.second] = 0;

}