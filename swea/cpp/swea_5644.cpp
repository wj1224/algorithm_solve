#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int T, Testcase;

int M, N, res;
int A[100];
int B[100];
int map[11][11][8][2];
vector<pair<pair<int, int>, pair<int, int>>> BC;
int A_cur[2] = { 1, 1 };
int B_cur[2] = { 10, 10 };

void MovePerson(int idx);
void MakeMap(void);
void Charge(void);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		cin >> M >> N;
		for (int i = 0; i < M; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		int temp[4];
		for (int i = 0; i < N; i++)
		{
			cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
			BC.push_back({ { temp[3], temp[2] },{ temp[1], temp[0] } });
		}
		sort(BC.begin(), BC.end(), greater<pair<pair<int, int>, pair<int, int>>>());

		MakeMap();
		Charge();
		for (int i = 0; i < M; i++)
		{
			MovePerson(i);
			Charge();
			A[i] = 0;
			B[i] = 0;
		}

		cout << "#" << T + 1 << " " << res << endl;

		BC.clear();
		res = 0;
		A_cur[0] = 1, A_cur[1] = 1;
		B_cur[0] = 10, B_cur[1] = 10;
		fill_n(&map[0][0][0][0], 11 * 11 * 8 * 2, 0);

	}

	return 0;

}

void MovePerson(int idx)
{

	if (A[idx] == 1)
		A_cur[0]--;
	else if (A[idx] == 2)
		A_cur[1]++;
	else if (A[idx] == 3)
		A_cur[0]++;
	else if (A[idx] == 4)
		A_cur[1]--;

	if (B[idx] == 1)
		B_cur[0]--;
	else if (B[idx] == 2)
		B_cur[1]++;
	else if (B[idx] == 3)
		B_cur[0]++;
	else if (B[idx] == 4)
		B_cur[1]--;

}

void MakeMap(void)
{

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			int k = 0;
			int index = 1;
			for (auto it = BC.begin(); it < BC.end(); it++)
			{
				int check_dist = abs(i - (*it).second.first) + abs(j - (*it).second.second);
				if (check_dist <= (*it).first.second)
				{
					map[i][j][k][0] = (*it).first.first;
					map[i][j][k][1] = index;
					k++;
				}
				index++;
			}
		}
	}

}

void Charge(void)
{

	if (map[A_cur[0]][A_cur[1]][0][1] == 0 && map[B_cur[0]][B_cur[1]][0][1] == 0)
		return;

	else if (map[A_cur[0]][A_cur[1]][0][1] != map[B_cur[0]][B_cur[1]][0][1])
		res += (map[A_cur[0]][A_cur[1]][0][0] + map[B_cur[0]][B_cur[1]][0][0]);

	else if (map[A_cur[0]][A_cur[1]][0][1] == map[B_cur[0]][B_cur[1]][0][1])
	{
		if (map[A_cur[0]][A_cur[1]][1][1] == 0 && map[B_cur[0]][B_cur[1]][1][1] == 0)
			res += map[A_cur[0]][A_cur[1]][0][0];
		else if (map[A_cur[0]][A_cur[1]][1][1] != 0 && map[B_cur[0]][B_cur[1]][1][1] == 0)
			res += (map[A_cur[0]][A_cur[1]][1][0] + map[B_cur[0]][B_cur[1]][0][0]);
		else if (map[A_cur[0]][A_cur[1]][1][1] == 0 && map[B_cur[0]][B_cur[1]][1][1] != 0)
			res += (map[A_cur[0]][A_cur[1]][0][0] + map[B_cur[0]][B_cur[1]][1][0]);
		else if (map[A_cur[0]][A_cur[1]][1][1] != 0 && map[B_cur[0]][B_cur[1]][1][1] != 0)
		{
			if (map[A_cur[0]][A_cur[1]][1][0] > map[B_cur[0]][B_cur[1]][1][0])
				res += (map[A_cur[0]][A_cur[1]][1][0] + map[B_cur[0]][B_cur[1]][0][0]);
			else
				res += (map[A_cur[0]][A_cur[1]][0][0] + map[B_cur[0]][B_cur[1]][1][0]);
		}
	}

}