#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first > b.first)
		return true;
	else if (a.first < b.first)
		return false;
	else
	{
		if (a.second > b.second)
			return false;
		else
			return true;
	}
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<pair<int, int>> v;
	int num1[5] = { 1, 2, 3, 4, 5 };
	int num2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int num3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	v.push_back(make_pair(0, 1));
	v.push_back(make_pair(0, 2));
	v.push_back(make_pair(0, 3));
	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == num1[i % 5])
			v[0].first++;
		if (answers[i] == num2[i % 8])
			v[1].first++;
		if (answers[i] == num3[i % 10])
			v[2].first++;
	}
	sort(v.begin(), v.end(), cmp);
	answer.push_back(v[0].second);
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first == v[0].first)
			answer.push_back(v[i].second);
	}

	return answer;
}