#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int T, N, K;
string str;
vector<int> v;

void calc()
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		int res = 0;
		int val = 1;
		for (int i = 0; i < N / 4 - 1; i++)
			val *= 16;
		for (int j = (N / 4) * idx; j < (N / 4) * (idx + 1); j++)
		{
			if ((str[j] - '0' >= 0) && (str[j] - '0') <= 9)
				res += ((str[j] - '0') * val);
			else if (str[j] == 'A')
				res += (10 * val);
			else if (str[j] == 'B')
				res += (11 * val);
			else if (str[j] == 'C')
				res += (12 * val);
			else if (str[j] == 'D')
				res += (13 * val);
			else if (str[j] == 'E')
				res += (14 * val);
			else if (str[j] == 'F')
				res += (15 * val);
			val /= 16;
		}
		v.push_back(res);
		idx++;
	}
}

void turn()
{
	char temp = str[str.size() - 1];
	for (int i = str.size() - 1; i >= 1; i--)
		str[i] = str[i - 1];
	str[0] = temp;
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		cin.ignore();
		getline(cin, str);
		for (int n = 0; n < N / 4; n++)
		{
			calc();
			turn();
		}
		sort(v.begin(), v.end(), greater<int>());
		int k = 1;
		int n = 1;
		int max_num = v[0];
		while (1)
		{
			if (k == K)
				break;
			if (max_num != v[n])
			{
				max_num = v[n];
				k++;
			}
			n++;
		}
		cout << "#" << t + 1 << " " << max_num << endl;
		str.clear();
		v.clear();
	}

	return 0;
}