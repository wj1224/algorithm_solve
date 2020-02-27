def solution(A,B):
	answer = 0
	
	A.sort()
	B.sort()
	while A:
		if A[0] <= B[0]:
			answer += A[0] * B[-1]
			A.pop(0)
			B.pop()
		else:
			answer += A[-1] * B[0]
			A.pop()
			B.pop(0)

	return answer
