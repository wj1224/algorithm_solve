// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int maxHei = -9999999;
int Hei = -1;

void solve(tree* T);

int solution(tree * T) {
	// write your code in C++14 (g++ 6.2.0)
	if (T == NULL)
		return -1;

	solve(T);

	return maxHei;
}

void solve(tree* T)
{
	if (T == NULL)
		return;

	Hei++;
	if (Hei > maxHei)
		maxHei = Hei;

	solve(T->l);
	solve(T->r);

	Hei--;

	return;
}