def solution(budgets, M):
	answer = 0
	budgets.sort()
	left = 0
	right = budgets[-1]
	mid = (left + right) // 2
	while left <= right:
		target = 0
		for i in range(len(budgets)):
			if budgets[i] > mid:
				target += (mid * (len(budgets) - i))
				break
			target += budgets[i]
		if target <= M:
			answer = mid
			left = mid + 1
			mid = (left + right) // 2
		else:
			right = mid - 1
			mid = (left + right) // 2
	return answer