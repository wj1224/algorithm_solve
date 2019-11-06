#include <string>
#include <vector>

using namespace std;

int mem[10000000];
int check[10000000];
int flag[7];
int answer;

void prime_num()
{
	for (int i = 2; i < 10000000; i++)
		mem[i] = 1;
	for (int i = 2; i * i < 10000000; i++)
	{
		if (mem[i] == 1)
		{
			for (int j = i * i; j <= 10000000; j += i)
				mem[j] = 0;
		}
	}
}

void dfs(string num, string numbers)
{
	if (num.size() > numbers.size() || num[0] == '0')
		return;
	if (mem[atoi(num.c_str())] == 1)
	{
		if (check[atoi(num.c_str())] == 0)
		{
			answer++;
			check[atoi(num.c_str())] = 1;
		}
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		if (flag[i] == 0)
		{
			flag[i] = 1;
			dfs(num + numbers[i], numbers);
			flag[i] = 0;
		}
	}
}

int solution(string numbers) {
	prime_num();
	dfs("", numbers);
	return answer;
}