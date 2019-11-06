answer = 99999

def check(a, b):
	cnt = 0
	for i in range(len(a)):
		cnt += 1 if a[i] == b[i] else 0
	return True if cnt == len(a) - 1 else False

def dfs(idx, begin, target, words, word, num):
	if begin == target:
		global answer
		if num < answer:
			answer = num
			return
	if idx >= len(words):
		return
	for i in range(len(words)):
		if not words[i] in word:
			if check(begin, words[i]):
				temp = begin
				begin = words[i]
				word.add(words[i])
				dfs(idx + 1, begin, target, words, word, num + 1)
				begin = temp
				word.remove(words[i])

def solution(begin, target, words):
	if not target in words:
		return 0
	word = set()
	dfs(0, begin, target, words, word, 0)
	
	return answer