# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	answer = 0
	j = 0
	right = []
	left = []
	for i in range(len(A)):
		right.append(i + A[i])
		left.append(i - A[i])
	right.sort()
	left.sort()
	for i in range(len(right)):
		while j < len(left):
			if right[i] >= left[j]:
				answer += (j - i)
				j += 1
			else:
				break
	if answer > 10000000:
		answer = -1
	return answer
