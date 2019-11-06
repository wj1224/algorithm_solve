def solution(brown, red):
	for r in range(1, red + 1):
		if red % r == 0:
			if brown == 2 * (r + (red // r)) + 4:
				return [red // r + 2, r + 2]