from itertools import combinations

def eratos(num):
	n = max(num)
	arr = [True] * (n + 1)
	res = 0
	
	for i in range(2, int(n ** 0.5) + 1):
		if arr[i] is True:
			for j in range(2 * i, n + 1, i):
				arr[j] = False
	for x in num:
		if arr[x] is True:
			res += 1
	return res

def solution(nums):
	comb = list(combinations(nums, 3))
	num = []
	for c in comb:
		num.append(c[0] + c[1] + c[2])
	answer = eratos(num)
	return answer
