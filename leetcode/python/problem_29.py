class Solution:
	def divide(self, dividend: int, divisor: int) -> int:
		minval, maxval, answer = -2 ** 31, 2 ** 31 - 1, 0
		if dividend < 0 and divisor > 0:
			sign = -1
		elif dividend > 0 and divisor < 0:
			sign = -1
		else:
			sign = 1
		dividend, divisor = abs(dividend), abs(divisor)
			
		while dividend >= divisor:
			temp = divisor
			num = 1
			while (temp << 1) <= dividend:
				temp = temp << 1
				num = num << 1
			answer += num
			dividend -= temp
		answer = sign * answer
		return max(min(maxval, answer), minval)
