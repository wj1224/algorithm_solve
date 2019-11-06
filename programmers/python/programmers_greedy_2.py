def solution(name):
	alpha = {"A" : 0, "B" : 1, "C" : 2, "D" : 3, "E" : 4, "F" : 5, "G" : 6, "H" : 7, "I" : 8, \
			"J" : 9, "K" : 10, "L" : 11, "M" : 12, "N" : 13, "O" : 12, "P" : 11, "Q" : 10, \
			"R" : 9, "S" : 8, "T" : 7, "U" : 6, "V" : 5, "W" : 4, "X" : 3, "Y" : 2, "Z" : 1}
	answer = 0
	check = [False] * len(name)
	check_num = 0
	pos = 0
	for idx, val in enumerate(name):
		if val == "A":
			check[idx] = True
			check_num += 1
	while True:
		if check[pos] is False:
			answer += alpha[name[pos]]
			check[pos] = True
			check_num += 1
		if check_num == len(name):
			break
		rp = pos
		lp = pos
		i = 1
		while True:
			rp = rp + 1 if rp < len(name) - 1 else 0
			if name[rp] != "A" and check[rp] is False:
				pos = rp
				answer += i
				break
			lp = lp - 1 if lp > 0 else len(name) - 1
			if name[lp] != "A" and check[lp] is False:
				pos = lp
				answer += i
				break
			i += 1
	return answer