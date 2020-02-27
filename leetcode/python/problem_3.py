class Solution:
	def lengthOfLongestSubstring(self, s: str) -> int:
		answer, num = 0, 0
		check = {}
		
		for idx, x in enumerate(s):
			if x not in check.keys() or (x in check.keys() and num > check[x]):
				answer = max(answer, idx - num + 1)
			else:
				num = check[x] + 1
			check[x] = idx
		
		return answer
