class Solution:
	def isValidSudoku(self, board: List[List[str]]) -> bool:
		row = [[False for _ in range(len(board))] for _ in range(len(board))]
		col = [[False for _ in range(len(board))] for _ in range(len(board))]
		box = [[False for _ in range(len(board))] for _ in range(len(board))]
		for i in range(len(board)):
			for j in range(len(board)):
				if board[i][j] != ".":
					k = (i // 3 * 3) + j // 3
					if row[i][int(board[i][j]) - 1] or col[j][int(board[i][j]) - 1] or \
						box[k][int(board[i][j]) - 1]:
						return False
					row[i][int(board[i][j]) - 1] = True
					col[j][int(board[i][j]) - 1] = True
					box[k][int(board[i][j]) - 1] = True
		return True
