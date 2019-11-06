from functools import reduce

def solution(n, times):
	left = 0
	right = max(times) * n
	mid = (left + right) // 2
	while left <= right:
		n_max = reduce(lambda x, y: x + y, map(lambda x: mid // x, times))
		if n_max < n:
			left = mid + 1
			mid = (left + right) // 2
		else:
			answer = mid
			right = mid - 1
			mid = (left + right) // 2
	return answer