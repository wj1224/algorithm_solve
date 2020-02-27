def solution(lines):
	answer = []
	eps = 10 ** -16
	logs = dict()
	traffic = [False] * len(lines)
	for i, l in enumerate(lines):
		date, etime, otime = l.split()
		h, m, s = etime.split(":")
		end_time = int(h) * 3600 + int(m) * 60 + float(s)
		start_time = end_time - float(otime[:-1]) + 0.001 - 1 + eps
		logs[start_time] = logs.get(start_time, []) + [i]
		logs[end_time] = logs.get(end_time, []) + [i]
	for l in sorted(logs.keys()):
		for i in logs[l]:
			idx = i
			traffic[idx] = False if traffic[idx] else True
			answer.append(traffic.count(True))
	return max(answer)
