sieve = [True] * 10000001
check = [False] * 10000001
num_check = [False] * 8
answer = 0

def Eratos():
	n = 10000001
	m = int(n ** 0.5)
	for i in range(2, m + 1):
		if sieve[i] == True:
			for j in range(i + i, n, i):
				sieve[j] = False
	sieve[0] = False
	sieve[1] = False
	return
  
def dfs(idx, n, num, numbers):
	if sieve[num] == True and check[num] == False:
		global answer
		answer += 1
		check[num] = True
	if idx >= n:
		return
	for i in range(n):
		if num_check[i] == False:
			num_check[i] = True
			dfs(idx + 1, n, int(str(num) + numbers[i]), numbers)
			num_check[i] = False
	return
	
def solution(numbers):
	Eratos()
	dfs(0, len(numbers), 0, numbers)
	return answer