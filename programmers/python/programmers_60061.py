def build_beam(arr, x, y):
	if (2 in arr[y][x] or 2 in arr[y][x + 1] or (4 in arr[y][x] and 3 in arr[y][x + 1])) and \
	x != len(arr) - 1 :
		arr[y][x].append(3)
		arr[y][x + 1].append(4)
	return arr

def build_pillar(arr, x, y):
	if (y == len(arr) - 1 or 3 in arr[y][x] or 4 in arr[y][x] or 2 in arr[y][x]) and y != 0:
		arr[y][x].append(1)
		arr[y - 1][x].append(2)
	return arr

def del_beam(arr, x, y):
	valid = [False] * 4
	if 1 in arr[y][x]:
		if 2 in arr[y][x] or 4 in arr[y][x]:
			valid[0] = True
	else:
		valid[0] = True

	if 1 in arr[y][x + 1]:
		if 2 in arr[y][x + 1] or 3 in arr[y][x + 1]:
			valid[1] = True
	else:
		valid[1] = True
	if 3 in arr[y][x + 1]:
		if 2 in arr[y][x + 1] or 2 in arr[y][x + 2]:
			valid[2] = True
	else:
		valid[2] = True
	if 4 in arr[y][x]:
		if 2 in arr[y][x] or 2 in arr[y][x - 1]:
			valid[3] = True
	else:
		valid[3] = True
	if False not in valid:
		arr[y][x].remove(3)
		arr[y][x + 1].remove(4)
	return arr

def del_pillar(arr, x, y):
	valid = [False] * 3
	if 1 in arr[y - 1][x]:
		if 3 in arr[y - 1][x] or 4 in arr[y - 1][x]:
			valid[0] = True
	else:
		valid[0] = True
	if 3 in arr[y - 1][x]:
		if 2 in arr[y - 1][x + 1] or (4 in arr[y - 1][x] and 3 in arr[y - 1][x + 1]):
			valid[1] = True
	else:
		valid[1] = True
	if 4 in arr[y - 1][x]:
		if 2 in arr[y - 1][x - 1] or (3 in arr[y - 1][x] and 4 in arr[y - 1][x - 1]):
			valid[2] = True
	else:
		valid[2] = True
	if False not in valid:
		arr[y][x].remove(1)
		arr[y - 1][x].remove(2)
	return arr

def make_answer(arr, answer):
	for i in range(len(arr)):
		for j in range(len(arr)):
			if 1 in arr[i][j]:
				answer.append([j, len(arr) - 1 - i, 0])
			if 3 in arr[i][j]:
				answer.append([j, len(arr) - 1 - i, 1])
	return sorted(answer, key=lambda x: (x[0], x[1]))

def solution(n, build_frame):
	answer = []
	arr = [[[] for _ in range(n + 1)] for _ in range(n + 1)]
	for oper in build_frame:
		if oper[2] == 0:
			if oper[3] == 0:
				arr = del_pillar(arr, oper[0], n - oper[1])
			else:
				arr = build_pillar(arr, oper[0], n - oper[1])
		else:
			if oper[3] == 0:
				arr = del_beam(arr, oper[0], n - oper[1])
			else:
				arr = build_beam(arr, oper[0], n - oper[1])
	answer = make_answer(arr, answer)
	return answer
