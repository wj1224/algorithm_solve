from itertools import permutations

def dfs(idx, weak, check_weak, dist, dist_idx, cur_dist, num_person):
	if False not in check_weak:
		return num_person
	elif idx >= len(weak) or dist_idx >= len(dist):
		return -1

	if weak[idx] - weak[idx - 1] <= cur_dist and check_weak[idx] is False:
		check_weak[idx] = True
		res = dfs(idx + 1, weak, check_weak, dist, dist_idx, \
				  cur_dist - weak[idx] + weak[idx - 1], num_person)
		check_weak[idx] = False
	elif weak[idx] - weak[idx - 1] > cur_dist and check_weak[idx] is False:
		if dist_idx + 1 < len(dist):
			check_weak[idx] = True
			res = dfs(idx + 1, weak, check_weak, dist, dist_idx + 1, dist[dist_idx + 1], num_person + 1)
			check_weak[idx] = False
		else:
			res = - 1

	return res

def solution(n, weak, dist):
	answer = len(dist) + 1
	for i in range(len(weak)):
		new_weak = weak[i:] + weak[:i]
		for j in range(1, len(new_weak)):
			if new_weak[j] < new_weak[j - 1]:
				new_weak[j] = n + new_weak[j]
		new_dist = list(permutations(dist))
		for d in new_dist:
			check_weak = [False] * len(new_weak)
			check_weak[0] = True
			if False not in check_weak:
				res = 1
			else:
				res = dfs(1, new_weak, check_weak, d, 0, d[0], 1)
			if res != -1:
				answer = min(answer, res)
	if answer == len(dist) + 1:
		answer = -1

	return answer
