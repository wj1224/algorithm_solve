def solution(genres, plays):
	answer = []
	genre = {}
	genre_plays = {}
	for i in range(len(genres)):
		genre[genres[i]] = genre.get(genres[i], 0) + plays[i]
		if genres[i] in genre_plays:
			genre_plays[genres[i]].append([plays[i], i])
		else:
			genre_plays[genres[i]] = []
			genre_plays[genres[i]].append([plays[i], i])
	genre_sorted = sorted(genre, key=lambda x: genre[x], reverse=True)
	for key, val in genre_plays.items():
		val.sort(key=lambda x: (-x[0], x[1]))
	for g in genre_sorted:
		for i in range(2):
			if (i >= len(genre_plays[g])):
				break
			answer.append(genre_plays[g][i][1])
	return answer
