#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int > v;

	for (int i = 0; i < reserve.size(); i++)
	{
		for (int j = 0; j < lost.size(); j++)
		{
			if (reserve[i] == lost[j])
			{
				lost.erase(lost.begin() + j);
				v.push_back(reserve[i]);
				break;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		auto it = find(reserve.begin(), reserve.end(), v[i]);
		if (it != reserve.end())
			reserve.erase(it);
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		for (int j = 0; j < lost.size(); j++)
		{
			if (reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j])
			{
				lost.erase(lost.begin() + j);
				break;
			}

		}
	}
	answer = n - lost.size();

	return answer;
}