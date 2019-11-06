#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < scoville.size(); i++)
		q.push(scoville[i]);
	while (1)
	{
		if (q.size() == 1 && q.top() < K)
			return -1;
		else if (q.size() == 1)
			return answer;
		if (q.top() >= K)
			return answer;
		int temp1 = q.top();
		q.pop();
		int temp2 = q.top();
		q.pop();
		q.push(temp1 + (temp2 * 2));
		answer++;
	}

	return answer;
}