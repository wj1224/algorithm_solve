#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int r, c, k;
int max_r = 3;
int max_c = 3;
int A[102][102];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

void oper_r()
{
	int num[101];
	vector<pair<int, int>> v;
	for (int i = 1; i <= max_r; i++)
	{
		memset(num, 0, sizeof(num));
		for (int j = 1; j <= max_c; j++)
		{
			if (A[i][j] == 0)
				continue;
			num[A[i][j]]++;
			A[i][j] = 0;
		}
		for (int j = 1; j < 101; j++)
		{
			if (num[j] != 0)
				v.push_back(make_pair(j, num[j]));
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;
		for (int j = 0; j < v.size(); j++)
		{
			if (idx > 100)
				break;
			A[i][idx] = v[j].first;
			A[i][idx + 1] = v[j].second;
			idx += 2;
		}
		if (idx - 1 > max_c)
			max_c = idx - 1;
		v.clear();
	}
}

void oper_c()
{
	int num[101];
	vector<pair<int, int>> v;
	for (int i = 1; i <= max_c; i++)
	{
		memset(num, 0, sizeof(num));
		for (int j = 1; j <= max_r; j++)
		{
			if (A[j][i] == 0)
				continue;;
			num[A[j][i]]++;
			A[j][i] = 0;
		}
		for (int j = 1; j < 101; j++)
		{
			if (num[j] != 0)
				v.push_back(make_pair(j, num[j]));
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;
		for (int j = 0; j < v.size(); j++)
		{
			if (idx > 100)
				break;
			A[idx][i] = v[j].first;
			A[idx + 1][i] = v[j].second;
			idx += 2;
		}
		if (idx - 1 > max_r)
			max_r = idx - 1;
		v.clear();
	}
}

int main()
{
	cin >> r >> c >> k;
	int ans = 0;
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			cin >> A[i][j];
	while (1)
	{
		if (A[r][c] == k || ans > 100)
			break;
		if (max_r >= max_c)
			oper_r();
		else
			oper_c();
		ans++;
	}
	if (ans == 101)
		ans = -1;
	cout << ans << endl;

	return 0;
}