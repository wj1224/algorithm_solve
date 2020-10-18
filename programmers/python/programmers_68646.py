def solution(a):
    answer = 2

    lmin = a[0]
    rmin = a[-1]
    for i in range(1, len(a) - 1):
        if a[i] < lmin:
            answer += 1
            lmin = a[i]
        if a[len(a) - 1 - i] < rmin:
            answer += 1
            rmin = a[len(a) - 1 - i]

    return answer if lmin != rmin else answer - 1
