class Solution:
	def multiply(self, num1: str, num2: str) -> str:
		answer = [0 for _ in range(len(num1) + len(num2))]
		
		for i1, n1 in enumerate(reversed(num1)):
			idx1 = len(num1) - 1 - i1
			for i2, n2 in enumerate(reversed(num2)):
				idx2 = len(num2) - 1 - i2
				int_n1, int_n2 = ord(n1) - ord('0'), ord(n2) - ord('0')
				answer[idx1 + idx2 + 1] += int_n1 * int_n2
				answer[idx1 + idx2] += answer[idx1 + idx2 + 1] // 10
				answer[idx1 + idx2 + 1] %= 10
		while len(answer) > 1 and answer[0] == 0:
			answer.pop(0)
		return ''.join(map(str, answer))
