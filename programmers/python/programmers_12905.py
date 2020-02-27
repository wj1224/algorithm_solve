def solution(board):
	sum1 = 0
	sum2 = 0
	for i in range(len(board[0])):
		sum1 += board[0][i]
	for i in range(len(board)):
		sum2 += board[i][0]
	answer = 0 if sum1 == 0 and sum2 == 0 else 1
	for i in range(1, len(board)):
		for j in range(1, len(board[i])):
			if board[i][j] == 1:
				board[i][j] = min(board[i][j - 1], board[i - 1][j], board[i - 1][j - 1]) + 1
				answer = max(answer, board[i][j])
	return answer ** 2
