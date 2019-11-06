#include <string>
#include <vector>

using namespace std;

long long mem[90];

long long solution(int N) {
	long long answer = 0;

	mem[0] = 4;
	mem[1] = 6;
	for (int i = 2; i <= N + 1; i++)
		mem[i] = mem[i - 2] + mem[i - 1];
	answer = mem[N - 1];

	return answer;
}