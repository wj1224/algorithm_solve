def solution(n, stations, w):
	answer = 0
	blocks = []
	
	left = 1
	for s in stations:
		right = s - w - 1
		if left <= right:
			blocks.append([left, right])
		left = s + w + 1
	if left <= n:
		blocks.append([left, n])
	for b in blocks:
		div, mod = (b[1] - b[0] + 1) // (w * 2 + 1), (b[1] - b[0] + 1) % (w * 2 + 1)
		answer += div + 1 if mod != 0  else div
		
	return answer
