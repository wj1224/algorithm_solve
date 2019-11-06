#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, L, cnt;
int map[100][100];
int check[100];
vector<int> v;

int main()
{

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			v.push_back(map[i][j]);
		}

		int nx = 0;
		int go = 0;

		while (nx < N - 1)
		{
			if (v[nx] == v[nx + 1])
				nx++;

			else if (v[nx] == v[nx + 1] + 1)
			{
				int sign = 0;
				for (int j = nx + 1; j <= nx + L; j++)
				{
					if (j < 0 || j >= N)
					{
						go = 1;
						break;
					}
					if (v[j] == v[nx + 1] && check[j] == 0)
					{
						sign++;
						check[j] = 1;
					}
				}
				if (sign != L)
				{
					go = 1;
					break;
				}
				nx += L;
			}

			else if (v[nx] == v[nx + 1] - 1)
			{
				int sign = 0;
				for (int j = nx; j >= nx - L + 1; j--)
				{
					if (j < 0 || j >= N)
					{
						go = 1;
						break;
					}
					if (v[j] == v[nx] && check[j] == 0)
					{
						sign++;
						check[j] = 1;
					}
				}
				if (sign != L)
				{
					go = 1;
					break;
				}
				nx++;
			}

			else
			{
				go = 1;
				break;
			}
		}

		if (go != 1)
			cnt++;

		memset(check, 0, sizeof(check));
		while (!v.empty())
			v.pop_back();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			v.push_back(map[j][i]);
		}

		int nx = 0;
		int go = 0;

		while (nx < N - 1)
		{
			if (v[nx] == v[nx + 1])
				nx++;

			else if (v[nx] == v[nx + 1] + 1)
			{
				int sign = 0;
				for (int j = nx + 1; j <= nx + L; j++)
				{
					if (j < 0 || j >= N)
					{
						go = 1;
						break;
					}
					if (v[j] == v[nx + 1] && check[j] == 0)
					{
						sign++;
						check[j] = 1;
					}
				}
				if (sign != L)
				{
					go = 1;
					break;
				}
				nx += L;
			}

			else if (v[nx] == v[nx + 1] - 1)
			{
				int sign = 0;
				for (int j = nx; j >= nx - L + 1; j--)
				{
					if (j < 0 || j >= N)
					{
						go = 1;
						break;
					}
					if (v[j] == v[nx] && check[j] == 0)
					{
						sign++;
						check[j] = 1;
					}
				}
				if (sign != L)
				{
					go = 1;
					break;
				}
				nx++;
			}

			else
			{
				go = 1;
				break;
			}
		}

		if (go != 1)
			cnt++;

		memset(check, 0, sizeof(check));
		while (!v.empty())
			v.pop_back();
	}

	cout << cnt << endl;

	return 0;

}