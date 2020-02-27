# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	ans = 0
	num_peaks = 0
	peaks = [False] * len(A)
	next_peaks = [0] * len(A)
	for i in range(1, len(A) - 1):
		if A[i] > A[i - 1] and A[i] > A[i + 1]:
			peaks[i] = True
			num_peaks += 1
	if num_peaks < 2:
		return num_peaks
	next_peaks[-1] = -1
	for i in range(len(A) - 2, -1, -1):
		if peaks[i]:
			next_peaks[i] = i
		else:
			next_peaks[i] = next_peaks[i + 1]
	i = 1
	while i * (i - 1) < len(A):
		j = 0
		num_flags = 0
		while j < len(A) and num_flags < i:
			j = next_peaks[j]
			if j == -1:
				break
			num_flags += 1
			j += i
		ans = max(ans, num_flags)
		i += 1
	return ans
