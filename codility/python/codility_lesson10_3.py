# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import heapq as hq

def solution(A):
	# write your code in Python 3.6
	peaks = [0] * (len(A) + 1)
	factors = set()
	for i in range(2, len(A) + 1):
		peaks[i] = peaks[i - 1]
		if i + 1 < len(peaks) and A[i - 1] > A[i - 2] and A[i - 1] > A[i]:
			peaks[i] += 1
	for i in range(2, int(len(A) ** 0.5) + 1):
		if len(A) % i == 0:
			factors.add(i)
			factors.add(len(A) // i)
	factors = list(factors)
	hq.heapify(factors)
	while len(factors) != 0:
		num = hq.heappop(factors)
		check = True
		for i in range(num , len(A) + 1, num):
			if peaks[i] == peaks[i - num]:
				check = False
				break
		if check:
			return len(A) // num
	if 1 in peaks:
		return 1
	else:
		return 0
