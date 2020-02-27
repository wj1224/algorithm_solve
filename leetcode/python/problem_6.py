from functools import reduce

class Solution:
	def convert(self, s: str, numRows: int) -> str:
		if numRows == 1:
			return s
		
		zigzag = ["" for _ in range(numRows)]
		idx = 0
		flag = True
		
		for char in s:
			zigzag[idx] += char
			if flag:
				idx += 1
			else:
				idx -= 1
			if idx == 0:
				flag = True
			elif idx == numRows - 1:
				flag = False
		return reduce(lambda x, y: x + y, zigzag)
