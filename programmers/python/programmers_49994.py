def solution(dirs):
	s = set()
	x, y, answer = 0, 0, 0
	for d in dirs:
		if d == "U":
			n_x, n_y = x, y - 1
		elif d == "D":
			n_x, n_y = x, y + 1
		elif d == "L":
			n_x, n_y = x - 1, y
		else:
			n_x, n_y = x + 1, y
		if n_x in range(-5, 6) and n_y in range(-5, 6):
			if (x, y, n_x, n_y) not in s:
				answer += 1
			s.add((x, y, n_x, n_y))
			s.add((n_x, n_y, x, y))
			x, y = n_x, n_y
	return answer
