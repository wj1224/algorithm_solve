def solution(s):
    answer = []
    s = s[1:-1].replace('},', '}.').split('.')
    s = sorted(s, key=len)

    for i in range(len(s)):
        for j in s[i][1:-1].split(','):
            if int(j) not in answer:
                answer.append(int(j))

    return answer
