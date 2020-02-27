import heapq as hq

def gcd(a, b):
	while b:
		a, b = b, a % b
	return a

def solution(arr):
	hq.heapify(arr)
	while len(arr) > 1:
		a = hq.heappop(arr)
		b = hq.heappop(arr)
		c = gcd(a, b)
		lcm = a * b // c
		hq.heappush(arr, lcm)
	return hq.heappop(arr)
