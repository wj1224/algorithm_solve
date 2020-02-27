# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from collections import Counter

def solution(A):
	# write your code in Python 3.6
	ans = 0
	if len(A) != 1:
		left = A[:1]
		right = A[1:]
		d_left = dict(Counter(left))
		d_right = dict(Counter(right))
		leader_left = max(d_left.keys(), key=lambda x: d_left[x])
		leader_right = max(d_right.keys(), key=lambda x: d_right[x])
		for i in range(len(A) - 1):
			if i != 0:
				d_left[A[i]] = d_left.get(A[i], 0) + 1
				if d_left[A[i]] > d_left[leader_left]:
					leader_left = A[i]
				d_right[A[i]] -= 1
				if d_right[A[i]] < d_right[leader_right]:
					leader_right = max(d_right.keys(), key=lambda x: d_right[x])
			if leader_left == leader_right and \
			d_left[leader_left] > (len(left) + i) / 2 and \
			d_right[leader_right] > (len(right) - i) / 2:
				ans += 1
	return ans
