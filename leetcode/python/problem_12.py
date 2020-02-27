class Solution:
	def intToRoman(self, num: int) -> str:
		symbol = ["M", "D", "C", "L", "X", "V", "I"]
		value = [1000, 500, 100, 50, 10, 5, 1]
		idx = 0
		answer = ""
		while num != 0:
			if str(num)[0] == "4":
				if len(str(num)) == 3:
					answer += "CD"
					num -= 400
				elif len(str(num)) == 2:
					answer += "XL"
					num -= 40
				elif len(str(num)) == 1:
					answer += "IV"
					num -= 4
			elif str(num)[0] == "9":
				if len(str(num)) == 3:
					answer += "CM"
					num -= 900
				elif len(str(num)) == 2:
					answer += "XC"
					num -= 90
				elif len(str(num)) == 1:
					answer += "IX"
					num -= 9
			else:
				div, mod = num // value[idx], num % value[idx]
				if div != 0:
					answer += symbol[idx] * div
				num = mod
			idx += 1
		return answer
