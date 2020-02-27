class Solution:
	def longestPalindrome(self, s: str) -> str:
		mem = []
		max_val = 1
		idx = [0, 0]
		
		for i in range(len(s)):
			mem.append([])
			for j in range(len(s)):
				if i == j or (i + 1 == j and s[i] == s[j]):
					mem[i].append(True)
					if i != j:
						max_val = 2
						idx = [i, j]
				else:
					mem[i].append(False)

		for i in range(2, len(s)):
			for j in range(len(s) - i):
				if s[j] == s[j + i] and mem[j + 1][j + i - 1] is True:
					mem[j][j + i] = True
					if i + 1 > max_val:
						max_val = i + 1
						idx = [j, j + i]

		return s[idx[0]:idx[1] + 1]
