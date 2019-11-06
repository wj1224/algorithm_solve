#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, Testcase;

string num;
vector<int> v;

int chrtonum(string s);
string numtochr(int sortnum);

int main()
{

	cin >> Testcase;

	for (T = 0; T < Testcase; T++)
	{

		string temp;
		int N;

		cin >> temp >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> num;
			v.push_back(chrtonum(num));
		}
		sort(v.begin(), v.end());

		cout << "#" << T + 1 << endl;
		for (int i = 0; i < N - 1; i++)
		{
			cout << numtochr(v[i]) << " ";
		}
		cout << numtochr(v[N - 1]) << endl;

		v.clear();

	}

	return 0;

}

int chrtonum(string s)
{

	if (s == "ZRO")
		return 0;
	else if (s == "ONE")
		return 1;
	else if (s == "TWO")
		return 2;
	else if (s == "THR")
		return 3;
	else if (s == "FOR")
		return 4;
	else if (s == "FIV")
		return 5;
	else if (s == "SIX")
		return 6;
	else if (s == "SVN")
		return 7;
	else if (s == "EGT")
		return 8;
	else if (s == "NIN")
		return 9;

}

string numtochr(int sortnum)
{

	if (sortnum == 0)
		return "ZRO";
	else if (sortnum == 1)
		return "ONE";
	else if (sortnum == 2)
		return "TWO";
	else if (sortnum == 3)
		return "THR";
	else if (sortnum == 4)
		return "FOR";
	else if (sortnum == 5)
		return "FIV";
	else if (sortnum == 6)
		return "SIX";
	else if (sortnum == 7)
		return "SVN";
	else if (sortnum == 8)
		return "EGT";
	else if (sortnum == 9)
		return "NIN";

}