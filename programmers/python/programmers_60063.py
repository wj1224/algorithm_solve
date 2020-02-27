def RotateCheck(board, x, y, s, d):
	if s == 0:
		if d == 0:
			if BoundaryCheck(len(board), x, y - 1, 1) and \
			board[y - 1][x] == 0 and board[y - 1][x + 1] == 0:
				return True
		elif d == 1:
			if BoundaryCheck(len(board), x + 1, y - 1, 1) and \
			board[y - 1][x + 1] == 0 and board[y - 1][x] == 0:
				return True
		elif d == 2:
			if BoundaryCheck(len(board), x, y, 1) and \
			board[y + 1][x] == 0 and board[y + 1][x + 1] == 0:
				return True
		else:
			if BoundaryCheck(len(board), x + 1, y, 1) and \
			board[y + 1][x + 1] == 0 and board[y + 1][x] == 0:
				return True
	else:
		if d == 0:
			if BoundaryCheck(len(board), x, y, 0) and \
			board[y][x + 1] == 0 and board[y + 1][x + 1] == 0:
				return True
		elif d == 1:
			if BoundaryCheck(len(board), x, y + 1, 0) and \
			board[y + 1][x + 1] == 0 and board[y][x + 1] == 0:
				return True
		elif d == 2:
			if BoundaryCheck(len(board), x - 1, y, 0) and \
			board[y][x - 1] == 0 and board[y + 1][x - 1] == 0:
				return True
		else:
			if BoundaryCheck(len(board), x - 1, y + 1, 0) and \
			board[y + 1][x - 1] == 0 and board[y][x - 1] == 0:
				return True
	return False

def MoveCheck(board, x, y, s):
	if s == 0:
		if board[y][x] == 0 and board[y][x + 1] == 0:
			return True
	else:
		if board[y][x] == 0 and board[y + 1][x] == 0:
			return True
	return False

def BoundaryCheck(n, x, y, s):
	if s == 0:
		if x >= 0 and x < n - 1 and y >= 0 and y < n:
			return True
	else:
		if y >= 0 and y < n - 1 and x >= 0 and x < n:
			return True
	return False

def bfs(board):
	n = len(board)
	q = [[0, 0, 0, 0]] # [x, y, state(horizontal 0 or vertical 1), time]
	dist = [[[2 ** 31 for _ in range(2)] for _ in range(n)] for _ in range(n)]
	dist[0][0][0] = 0
	dx = [1, 0, -1, 0]
	dy = [0, 1, 0, -1]
	hor_rotate_dx = [0, 1, 0, 1]
	hor_rotate_dy = [-1, -1, 0, 0]
	ver_rotate_dx = [0, 0, -1, -1]
	ver_rotate_dy = [0, 1, 0, 1]
	
	while q:
		x, y, s, t = q.pop()
		
		# Move
		for i in range(4):
			nx = x + dx[i]
			ny = y + dy[i]
			if BoundaryCheck(n, nx, ny, s) and MoveCheck(board, nx, ny, s):
				if dist[ny][nx][s] > t + 1:
					dist[ny][nx][s] = t + 1
					q.append([nx, ny, s, t + 1])
		
		# Rotate
		if s == 0:
			for i in range(4):
				if RotateCheck(board, x, y, 0, i):
					nx = x + hor_rotate_dx[i]
					ny = y + hor_rotate_dy[i]
					if dist[ny][nx][1] > t + 1:
						dist[ny][nx][1] = t + 1
						q.append([nx, ny, 1, t + 1])
		else:
			for i in range(4):
				if RotateCheck(board, x, y, 1, i):
					nx = x + ver_rotate_dx[i]
					ny = y + ver_rotate_dy[i]
					if dist[ny][nx][0] > t + 1:
						dist[ny][nx][0] = t + 1
						q.append([nx, ny, 0, t + 1])
						
	return min(dist[n - 1][n - 2][0], dist[n - 2][n - 1][1])
		
def solution(board):
	answer = bfs(board)
	return answer
