# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
	# write your code in Python 3.6
	answer = 1
	d = {")" : "(", "]" : "[", "}" : "{"}
	l = []
	if len(S) != 0:
		for s in S:
			if s == "(" or s == "[" or s == "{":
				l.append(s)
			else:
				if len(l) != 0 and l[-1] == d[s]:
					l.pop()
				else:
					answer = 0
					break
		if len(l) != 0:
			answer = 0
	return answer
