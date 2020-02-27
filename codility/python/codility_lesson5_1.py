# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	answer = 0
	car_east = 0
	for a in A:
		car_east += 1 if a == 0 else 0
		answer += car_east if a == 1 else 0
		if answer > 1000000000:
			answer = -1
			break
	return answer
