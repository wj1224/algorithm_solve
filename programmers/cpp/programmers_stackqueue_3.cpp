#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<int> v;

	answer.push_back(0);
	v.push_back(heights[0]);
	for (int i = 1; i < heights.size(); i++)
	{
		for (int j = v.size() - 1; j >= 0; j--)
		{
			if (heights[i] < v[j])
			{
				answer.push_back(j + 1);
				break;
			}
			if (j == 0)
				answer.push_back(0);
		}
		v.push_back(heights[i]);
	}

	return answer;
}