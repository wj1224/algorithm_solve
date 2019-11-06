#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (1)
	{
		if (progresses.empty())
			break;
		int cnt = 0;
		for (int i = 0; i < progresses.size(); i++)
			progresses[i] += speeds[i];
		for (int i = 0; i < progresses.size(); i++)
		{
			if (progresses[i] < 100)
				break;
			cnt++;
		}
		if (cnt != 0)
		{
			progresses.erase(progresses.begin(), progresses.begin() + cnt);
			speeds.erase(speeds.begin(), speeds.begin() + cnt);
			answer.push_back(cnt);
			cnt = 0;
		}
	}

	return answer;
}