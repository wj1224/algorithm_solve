#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[20][20];
int minValue = 99999999;
vector<int> start;
vector<int> link;

void dfs(int idx);
int calc();

int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0);

	cout << minValue << endl;

	return 0;

}

void dfs(int idx)
{
	if (start.size() > N / 2 || link.size() > N / 2 || idx == N + 1)
		return;

	if (start.size() == N / 2 && link.size() == N / 2)
	{
		int res = calc();
		if (res < minValue)
			minValue = res;
		return;
	}

	start.push_back(idx);
	dfs(idx + 1);
	start.pop_back();

	link.push_back(idx);
	dfs(idx + 1);
	link.pop_back();

}

int calc()
{

	int start_sum = 0;
	int link_sum = 0;

	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			start_sum += arr[start[i]][start[j]];
			link_sum += arr[link[i]][link[j]];
		}
	}

	return abs(start_sum - link_sum);

}