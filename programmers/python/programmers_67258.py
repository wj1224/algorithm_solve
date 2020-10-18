from collections import defaultdict

def solution(gems):
    answer = [0, 100001]
    num_gems = len(set(gems))
    stand = defaultdict(int)
    left, right = 0, 0
    stand[gems[right]] += 1
    
    while left < len(gems) and right < len(gems):
        if len(stand) == num_gems:
            if right - left < answer[1] - answer[0]:
                answer = [left, right]
            stand[gems[left]] -= 1
            if stand[gems[left]] == 0:
                del stand[gems[left]]
            left += 1
            continue
        right += 1
        try:
            stand[gems[right]] += 1
        except IndexError:
            break
    return [answer[0] + 1, answer[1] + 1]
