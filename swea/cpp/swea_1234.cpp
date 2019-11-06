#include <iostream>
#include <stack>

using namespace std;

int T, Testcase;

int N;
char temp;
char res[101];
stack<char> s;

int main()
{

	Testcase = 10;

	for (T = 0; T < Testcase; T++)
	{

		cin >> N;

		for (int i = 0; i < N; i++)
		{

			cin >> temp;
			if (s.empty())
				s.push(temp);
			else
			{
				if (temp == s.top())
					s.pop();
				else
					s.push(temp);
			}

		}

		int stop = s.size();

		for (int i = s.size() - 1; i >= 0; i--)
		{
			res[i] = s.top();
			s.pop();
		}

		cout << "#" << T + 1 << " ";
		for (int i = 0; i < stop; i++)
			cout << res[i];
		cout << endl;

		fill(&res[0], &res[101], 0);

	}

	return 0;

}