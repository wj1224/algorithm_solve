#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(int idx, vector<int> numbers, int res, int target);

int solution(vector<int> numbers, int target) {
	dfs(0, numbers, 0, target);
	return answer;
}

void dfs(int idx, vector<int> numbers, int res, int target)
{
	if (idx == numbers.size())
	{
		if (res == target)
			answer++;
		return;
	}
	dfs(idx + 1, numbers, res + numbers[idx], target);
	dfs(idx + 1, numbers, res - numbers[idx], target);
}