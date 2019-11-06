#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	vector<int> v;

	sort(citations.begin(), citations.end(), greater<int>());
	if (citations[0] == 0)
		return 0;
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] >= answer)
		{
			answer++;
			v.push_back(citations[i]);
		}
		else
			break;
	}
	sort(v.begin(), v.end(), greater<int>());
	while (1)
	{
		if (v[v.size() - 1] >= answer)
			break;
		v.pop_back();
	}
	answer = v.size();

	return answer;
}