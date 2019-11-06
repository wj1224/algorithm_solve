def solution(operations):
	q = []
	for o in operations:
		oper, num = o.split()
		if oper == "I":
			q.append(int(num))
		else:
			if q:
				if num == "1":
					print(max(q))
					q.remove(max(q))
				else:
					print(min(q))
					q.remove(min(q))
					
	if not q:
		return [0, 0]
				
	return [max(q), min(q)]