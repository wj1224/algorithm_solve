def solution(land):
	dp = [[0 for _ in range(4)] for _ in range(len(land))]
	for x in range(4):
		dp[0][x] = land[0][x]
	
	for i in range(1, len(land)):
		for j in range(4):
			dp[i][j] = max(dp[i - 1][:j] + dp[i - 1][j + 1:]) + land[i][j]

	return max(dp[-1])
