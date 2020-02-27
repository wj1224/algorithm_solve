def rotate(key):
	rotate_key = [[0 for _ in range(len(key))] for _ in range(len(key))]
	for i in range(len(key)):
		for j in range(len(key)):
			rotate_key[i][j] = key[len(key) - 1 - j][i]
	return rotate_key

def expand(lock):
	expand_lock = [[0 for _ in range(len(lock) * 3 - 2)] for _ in range(len(lock) * 3 - 2)]
	for i in range(len(lock)):
		for j in range(len(lock)):
			expand_lock[i + len(lock) - 1][j + len(lock) - 1] = lock[i][j]
	return expand_lock

def check(key, expand_lock, x, y, N):
	for i in range(len(key)):
		for j in range(len(key)):
			expand_lock[y + i][x + j] += key[i][j]
	for i in range(N):
		for j in range(N):
			if expand_lock[N - 1 + i][N - 1 + j] != 1:
				for k_i in range(len(key)):
					for k_j in range(len(key)):
						expand_lock[y + k_i][x + k_j] -= key[k_i][k_j]
				return False
	for i in range(len(key)):
		for j in range(len(key)):
			expand_lock[y + i][x + j] -= key[i][j]
	return True

def solution(key, lock):
	expand_lock = expand(lock)
	for i in range(len(expand_lock) - len(key) + 1):
		for j in range(len(expand_lock) - len(key) + 1):
			for _ in range(4):
				key = rotate(key)
				if check(key, expand_lock, j, i, len(lock)):
					return True
	return False
