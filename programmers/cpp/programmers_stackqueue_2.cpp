#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 1;
	vector<pair<int, int>> v;

	for (int i = 0; i < priorities.size(); i++)
		v.push_back(make_pair(priorities[i], i));
	while (1)
	{
		for (int j = 1; j < v.size(); j++)
		{
			if (v[0].first < v[j].first)
			{
				v.push_back(make_pair(v[0].first, v[0].second));
				v.erase(v.begin());
				break;
			}
			if (j == v.size() - 1 && v[0].second != location)
			{
				answer++;
				v.erase(v.begin());
			}
			else if (j == v.size() - 1 && v[0].second == location)
				return answer;
		}
		if (v.size() == 1)
			return answer;
	}

}