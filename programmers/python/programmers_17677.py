def solution(str1, str2):
    valid = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
             'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    str1, str2 = str1.lower(), str2.lower()
    set1, set2, interset, unionset = dict(), dict(), dict(), dict()
    for i in range(len(str1) - 1):
        if str1[i] in valid and str1[i + 1] in valid:
            set1[str1[i] + str1[i + 1]] = set1.get(str1[i] + str1[i + 1], 0) + 1
    for i in range(len(str2) - 1):
        if str2[i] in valid and str2[i + 1] in valid:
            set2[str2[i] + str2[i + 1]] = set2.get(str2[i] + str2[i + 1], 0) + 1
    for key, val in set1.items():
        if key in set2.keys():
            interset[key] = min(set1[key], set2[key])
            unionset[key] = max(set1[key], set2[key])
        else:
            unionset[key] = set1[key]
    for key, val in set2.items():
        if key not in unionset:
            unionset[key] = set2[key]
    
    if len(interset) == 0 and len(unionset) == 0:
        return 65536
    answer = int(sum(list(interset.values())) / sum(list(unionset.values())) * 65536)
    return answer
