#include <iostream>
#include <vector>

using namespace std;

int T, Testcase;
vector<int> v;
vector<int>::iterator it;

int main()
{

	Testcase = 10;

	for (T = 0; T < Testcase; T++)
	{

		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{

			int temp;
			cin >> temp;
			v.push_back(temp);

		}

		int num_oper;
		cin >> num_oper;

		for (int i = 0; i < num_oper; i++)
		{

			char oper;
			int x, y;
			cin >> oper;

			if (oper == 'I')
			{

				cin >> x >> y;

				it = v.begin() + x;

				for (int j = 0; j < y; j++)
				{
					int num;
					cin >> num;
					it = v.insert(it, num);
					it++;

				}

			}

			else if (oper == 'D')
			{

				cin >> x >> y;

				it = v.begin() + x;

				v.erase(it, it + y);

			}

		}

		cout << "#" << T + 1;
		for (int i = 0; i < 10; i++)
			cout << " " << v[i];
		cout << endl;

		v.clear();

	}

	return 0;

}