def solution(N):
	mem = [0] * (N + 1)
	mem[1] = 4
	mem[2] = 6
	for i in range(3, N + 1):
		mem[i] = mem[i - 2] + mem[i - 1]
	return mem[N]