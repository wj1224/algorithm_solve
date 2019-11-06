#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sum = 0;
	queue<pair<int, int>> q;

	int i = 0;
	while (1)
	{
		if (i < truck_weights.size())
		{
			if (q.empty() || sum + truck_weights[i] <= weight)
			{
				q.push(make_pair(truck_weights[i], answer));
				sum += truck_weights[i];
				i++;
			}
		}
		if (!q.empty() && q.front().second + bridge_length <= answer + 1)
		{
			sum -= q.front().first;
			q.pop();
		}
		answer++;
		if (i >= truck_weights.size() && q.empty())
			break;
	}
	answer++;
	return answer;
}