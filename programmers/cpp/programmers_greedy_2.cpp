#include <string>
#include <vector>

using namespace std;

int num_alpha[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

int solution(string name) {
	int answer = 0;
	int cur = 0;
	int num = 0;
	int cnt = 0;
	int cnt_right = 0;
	int cnt_left = 0;
	int* check = new int[name.size()]();

	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != 'A')
			num++;
	}
	while (1)
	{
		answer += (num_alpha[name[cur] - 65] + cnt_right + cnt_left);
		if (name[cur] != 'A')
		{
			check[cur] = 1;
			cnt++;
		}
		if (num == cnt)
			break;
		int temp_right = cur;
		int temp_left = cur;
		cnt_right = 0;
		cnt_left = 0;
		while (1)
		{
			if (temp_right < name.size() - 1)
				temp_right++;
			else
				temp_right = 0;
			cnt_right++;
			if (check[temp_right] == 0 && name[temp_right] != 'A')
			{
				cur = temp_right;
				cnt_left = 0;
				break;
			}
			if (temp_left > 0)
				temp_left--;
			else
				temp_left = name.size() - 1;
			cnt_left++;
			if (check[temp_left] == 0 && name[temp_left] != 'A')
			{
				cur = temp_left;
				cnt_right = 0;
				break;
			}
		}
	}
	delete[] check;

	return answer;
}