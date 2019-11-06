#include <iostream>
#include <stack>

using namespace std;

int T, Testcase;

int price[4];
int plan[14];
int minValue = 999999999;
int lastP;
stack<int> s;

void solve(int idx, int sum);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		for (int i = 0; i < 4; i++)
			cin >> price[i];
		for (int i = 0; i < 12; i++)
		{
			cin >> plan[i];
			if (plan[i] != 0)
				lastP = i;
		}

		solve(0, 0);

		cout << "#" << T + 1 << " " << minValue << endl;

		minValue = 999999999;
		lastP = 0;
		while (!s.empty())
			s.pop();

	}

	return 0;

}

void solve(int idx, int sum)
{
	if (sum > price[3])
	{
		if (price[3] < minValue)
			minValue = price[3];
		return;
	}

	int fplan = 0;
	for (int k = 0; k < 12; k++)
		fplan += plan[k];

	if (fplan == 0)
	{
		if (sum < minValue)
			minValue = sum;
		return;
	}

	for (int i = idx; i < 12; i++)
	{

		if (plan[i] > 0)
		{
			if (plan[i] * price[0] < price[1])
			{
				s.push(plan[i]);
				plan[i] = 0;
				solve(i + 1, sum + (price[0] * s.top()));
				plan[i] = s.top();
				s.pop();
			}

			else
			{
				s.push(plan[i]);
				plan[i] = 0;
				solve(i + 1, sum + price[1]);
				plan[i] = s.top();
				s.pop();
			}

			s.push(plan[i]);
			s.push(plan[i + 1]);
			s.push(plan[i + 2]);
			plan[i] = 0;
			plan[i + 1] = 0;
			plan[i + 2] = 0;
			solve(i + 3, sum + price[2]);
			plan[i + 2] = s.top();
			s.pop();
			plan[i + 1] = s.top();
			s.pop();
			plan[i] = s.top();
			s.pop();

		}
	}

}