class Solution:
	def myAtoi(self, str: str) -> int:
		answer = 0
		min_val, max_val = -2 ** 31, 2 ** 31 - 1
		s = list(str.strip())
		if len(s) == 0:
			return answer
		
		flag = -1 if s[0] == "-" else 1
		for i in range(len(s)):
			if i == 0 and s[i] in ["+", "-"]:
				continue
			if s[i].isdigit() is False:
				break
			answer = 10 * answer + ord(s[i]) - ord("0")
		answer *= flag
		
		return max(min_val, min(max_val, answer))
