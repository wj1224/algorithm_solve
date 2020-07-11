def solution(cacheSize, cities):
    answer = 0
    cache = []
    if cacheSize == 0 or cacheSize >= len(cities):
        return 5 * len(cities)
    for c in cities:
        if len(cache) < cacheSize:
            if c.lower() in cache:
                cache.remove(c.lower())
                cache.append(c.lower())
                answer += 1
            else:
                cache.append(c.lower())
                answer += 5
        else:
            if c.lower() in cache:
                cache.remove(c.lower())
                cache.append(c.lower())
                answer += 1
            else:
                cache.pop(0)
                cache.append(c.lower())
                answer += 5
    return answer
