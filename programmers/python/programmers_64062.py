def solution(stones, k):
    left, right = 1, 200000000
    while left <= right:
        mid = (left + right) // 2
        stones_cp = list(map(lambda x: x - mid, stones))
        cnt = 0
        for i in range(len(stones_cp)):
            if stones_cp[i] < 0:
                cnt += 1
            if cnt >= k:
                right = mid - 1
                break
            if cnt > 0 and stones_cp[i] >= 0:
                cnt = 0
        else:
            left = mid + 1
    
    return ((left + right) // 2)
