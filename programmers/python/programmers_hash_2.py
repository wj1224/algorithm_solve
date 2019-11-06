def solution(phone_book):
	answer = True
	phone_book.sort()
	for i, v in enumerate(phone_book[:-1]):
		if v in phone_book[i + 1]:
			answer = False
	return answer
