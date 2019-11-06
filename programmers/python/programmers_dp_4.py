def solution(m, n, puddles):
	arr = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
	mem = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
	mem[0][1] = 1
	for p in puddles:
		arr[p[1]][p[0]] = 1
	for i in range(1, n + 1):
		for j in range(1, m + 1):
			mem[i][j] = 0 if arr[i][j] == 1 else mem[i - 1][j] + mem[i][j - 1]
	return mem[n][m] % 1000000007