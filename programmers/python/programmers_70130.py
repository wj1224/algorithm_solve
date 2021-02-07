from collections import Counter

def solution(a):
    if len(a) <= 2:
        return 0

    answer = -1
    nums = Counter(a)

    for num in nums.keys():
        if answer >= nums[num]:
            continue
        cnt = 0
        i = 0
        while i < len(a) - 1:
            if (a[i] != num and a[i + 1] != num) or (a[i] == a[i + 1]):
                i += 1
                continue
            cnt += 1
            i += 2
        answer = max(answer, cnt)

    return answer * 2
