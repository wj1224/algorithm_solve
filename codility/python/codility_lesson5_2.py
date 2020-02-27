# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S, P, Q):
	# write your code in Python 3.6
	d = {"A" : 1, "C" : 2, "G" : 3, "T" : 4}
	num_dict = {"A" : [0] * (len(S) + 1), "C" : [0] * (len(S) + 1), \
	"G" : [0] * (len(S) + 1), "T" : [0] * (len(S) + 1)}
	answer = []
	for i in range(1, len(S) + 1):
		for key in num_dict:
			num_dict[key][i] = num_dict[key][i - 1] if key != S[i - 1] \
			else num_dict[key][i - 1] + 1
	for p, q in zip(P, Q):
		if p == q:
			answer.append(d[S[p]])
			continue
		if num_dict["A"][p] != num_dict["A"][q + 1]:
			answer.append(1)
		else:
			if num_dict["C"][p] != num_dict["C"][q + 1]:
				answer.append(2)
			else:
				if num_dict["G"][p] != num_dict["G"][q + 1]:
					answer.append(3)
				else:
					answer.append(4)
	return answer
