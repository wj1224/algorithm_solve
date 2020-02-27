def solution(w,h):
	answer = w * h
	if w == h:
		answer -= w
	else:
		a, b = max(w, h), min(w, h)
		while (b != 0):
			a, b = b, a % b
		answer -= a * (w // a + h // a - 1)
	return answer
