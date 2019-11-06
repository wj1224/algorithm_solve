#include <iostream>
#include <stack>

using namespace std;

int T, Testcase, N;

int res = 1;
char bracket;

stack<char> s;

int main() {

	Testcase = 10;

	for (T = 0; T < 10; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {

			cin >> bracket;

			if (s.empty() && (bracket == ')' || bracket == ']' || bracket == '}' || bracket == '>'))
				res = 0;

			else if (bracket == '(' || bracket == '[' || bracket == '{' || bracket == '<')
				s.push(bracket);

			else {
				if (s.top() == '(' && bracket == ')')
					s.pop();
				else if (s.top() == '[' && bracket == ']')
					s.pop();
				else if (s.top() == '{' && bracket == '}')
					s.pop();
				else if (s.top() == '<' && bracket == '>')
					s.pop();
				else
					res = 0;
			}
		}

		if (!s.empty())
			res = 0;

		cout << "#" << T + 1 << " " << res << endl;

		res = 1;

		while (!s.empty())
			s.pop();

	}

	return 0;

}