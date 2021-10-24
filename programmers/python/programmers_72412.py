from collections import defaultdict

def bin_search(arr, target):
    left, right = 0, len(arr) - 1

    while left < right:
        mid = (left + right) // 2
        if arr[mid] >= target:
            right = mid
        else:
            left = mid + 1

    return len(arr) - right

def solution(info, query):
    answer = []
    applicants = defaultdict(list)

    for i in range(len(info)):
        n = info[i].split(" ")
        lang, task, car, food = n[0][0], n[1][0], n[2][0], n[3][0]
        for l in [lang, "-"]:
            for t in [task, "-"]:
                for c in [car, "-"]:
                    for f in [food, "-"]:
                        applicants[l + t + c + f].append(int(n[4]))

    for key in applicants.keys():
        applicants[key] = sorted(applicants[key])

    for q in query:
        cond = q.split(" ")
        key = cond[0][0] + cond[2][0] + cond[4][0] + cond[6][0]
        val = int(cond[7])
        if key in applicants.keys() and val <= applicants[key][-1]:
            answer.append(bin_search(applicants[key], val))
        else:
            answer.append(0)

    return answer
