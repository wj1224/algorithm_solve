def solution(n):
	mem = [0] * n
	mem[0] = 1
	mem[1] = 2
	for i in range(2, n):
		mem[i] = (mem[i - 1] + mem[i - 2]) % 1000000007
	return mem[n - 1]
