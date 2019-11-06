# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
	# write your code in Python 3.6
	n = bin(N)[2:]
	pos = []
	maxval = 0
	for idx, val in enumerate(n):
		if val == "1" and len(pos) == 0:
			pos.append(idx)
		elif val == "1" and len(pos) != 0:
			maxval = idx - pos[0] - 1 if idx - pos[0] - 1 > maxval else maxval
			pos[0] = idx

	return maxval