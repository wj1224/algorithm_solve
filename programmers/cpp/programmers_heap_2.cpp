#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int idx = 0;
	priority_queue<pair<int, int>> q;

	for (int i = 0; i < k; i++)
	{
		if (i == dates[idx])
		{
			q.push(make_pair(supplies[idx], dates[idx]));
			idx++;
		}
		if (stock == 0)
		{
			stock += q.top().first;
			q.pop();
			answer++;
		}
		stock--;
	}

	return answer;
}