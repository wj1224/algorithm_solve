#include <iostream>
#include <stack>

using namespace std;

int T, Testcase;

int N;
int k;
stack<int> s;
stack<int> s2;
char equ;
char postfix[1000];
int num1, num2, res;

int main() {

	Testcase = 10;

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < N; i++) {

			cin >> equ;

			if (equ >= '0' && equ <= '9')
				postfix[k++] = equ;

			else if (equ == '(')
				s.push(equ);

			else if (equ == ')') {

				while (s.top() != '(') {

					postfix[k++] = s.top();
					s.pop();

				}

				s.pop(); // '(' Á¦°Å

			}

			else if (equ == '+' || equ == '-') {

				if (!s.empty()) {

					while ((!s.empty()) && (s.top() == '*' || s.top() == '/')) {

						postfix[k++] = s.top();
						s.pop();

					}

				}

				s.push(equ);

			}

			else if (equ == '*' || equ == '/')
				s.push(equ);

		}

		while (!s.empty()) {

			postfix[k++] = s.top();
			s.pop();

		}

		for (int i = 0; i < N; i++) {

			if (postfix[i] >= '0' && postfix[i] <= '9')
				s2.push(postfix[i] - '0');

			else if (postfix[i] == '*') {

				num1 = s2.top();
				s2.pop();
				num2 = s2.top();
				s2.pop();
				res = num1 * num2;
				s2.push(res);

			}

			else if (postfix[i] == '/') {

				num1 = s2.top();
				s2.pop();
				num2 = s2.top();
				s2.pop();
				res = num1 / num2;
				s2.push(res);

			}

			else if (postfix[i] == '+') {

				num1 = s2.top();
				s2.pop();
				num2 = s2.top();
				s2.pop();
				res = num1 + num2;
				s2.push(res);

			}

			else if (postfix[i] == '-') {

				num1 = s2.top();
				s2.pop();
				num2 = s2.top();
				s2.pop();
				res = num1 - num2;
				s2.push(res);

			}

			postfix[i] = 0;

		}

		res = s2.top();
		s2.pop();
		k = 0;

		cout << "#" << T + 1 << " " << res << endl;

	}

	return 0;

}