# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N, A):
	# write your code in Python 3.6
	cnt = [0] * N
	maxval = 0
	cur_max = 0
	for a in A:
		if a <= N:
			cnt[a - 1] = (maxval + 1) if cnt[a - 1] <= maxval else cnt[a - 1] + 1
			if cnt[a - 1] > cur_max:
				cur_max += 1
		else:
			maxval = cur_max
	for i in range(len(cnt)):
		cnt[i] = maxval if cnt[i] < maxval else cnt[i]
	return cnt
