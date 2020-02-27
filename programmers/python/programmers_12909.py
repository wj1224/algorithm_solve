def solution(s):
	a = []
	for i in s:
		if i == '(':
			a.append(i)
		else:
			if len(a) != 0:
				a.pop()
			else:
				return False
	if len(a) != 0:
		return False
	else:
		return True
