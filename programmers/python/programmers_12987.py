def solution(A, B):
	answer = 0
	A.sort(reverse=True)
	B.sort(reverse=True)
	while B:
		if B[0] > A[0]:
			answer += 1
			A.pop(0)
			B.pop(0)
		else:
			A.pop(0)
			B.pop()
	return answer
