#include <iostream>
#include <queue>

using namespace std;

int T, Testcase;

int N, M, K, A, B;

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		int a[10] = { 0, };
		int b[10] = { 0, };
		int t[1001] = { 0, };
		int a_ready[10][2] = { 0, };
		int b_ready[10][2] = { 0, };
		int res[1001][2] = { 0, };
		queue<int> q1, q2;

		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> a[i];
		for (int i = 1; i <= M; i++)
			cin >> b[i];
		for (int i = 1; i <= K; i++)
			cin >> t[i];

		int people_idx = 1;
		int a_endcheck = 0;
		int b_endcheck = 0;

		for (int tt = 0; tt < 10000; tt++)
		{

			for (int i = 1; i <= N; i++)
			{
				a_endcheck += a_ready[i][0];
			}
			for (int i = 1; i <= M; i++)
			{
				b_endcheck += b_ready[i][0];
			}
			if (q1.empty() && q2.empty() && a_endcheck == 0 && b_endcheck == 0 && people_idx >= K)
				break;
			else
			{
				a_endcheck = 0;
				b_endcheck = 0;
			}

			for (int i = 1; i <= N; i++)
			{
				if (a_ready[i][0] == tt && tt != 0)
				{
					a_ready[i][0] = 0;
					q2.push(a_ready[i][1]);
					a_ready[i][1] = 0;
				}
			}
			for (int i = 1; i <= M; i++)
			{
				if (b_ready[i][0] == tt && tt != 0)
				{
					b_ready[i][0] = 0;
					b_ready[i][1] = 0;
				}
			}

			while (t[people_idx] == tt)
			{
				q1.push(people_idx);
				people_idx++;
			}

			for (int i = 1; i <= N; i++) {
				if (a_ready[i][0] == 0 && !q1.empty())
				{
					res[q1.front()][0] = i;
					a_ready[i][0] = tt + a[i];
					a_ready[i][1] = q1.front();
					q1.pop();
				}
			}

			for (int i = 1; i <= M; i++) {
				if (b_ready[i][0] == 0 && !q2.empty())
				{
					res[q2.front()][1] = i;
					b_ready[i][0] = tt + b[i];
					b_ready[i][1] = q2.front();
					q2.pop();
				}
			}

		}

		int num = 0;
		for (int i = 0; i < people_idx; i++)
		{
			if (res[i][0] == A && res[i][1] == B)
				num += i;
		}
		if (num == 0)
			num = -1;

		cout << "#" << T + 1 << " " << num << endl;

	}

	return 0;

}