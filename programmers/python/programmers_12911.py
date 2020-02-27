def solution(n):
	n_bin = bin(n)[2:]
	num = n_bin.count('1')
	while True:
		n += 1
		temp = bin(n)[2:]
		if temp.count('1') == num:
			return n
