def solution(s):
    answer = []
    for subs in s:
        remains = 0
        stack = []
        for char in subs:
            if len(stack) >= 2 and stack[-1] == "1" and stack[-2] == "1" and char == "0":
                stack.pop()
                stack.pop()
                remains += 1
            else:
                stack.append(char)
        subs = ''.join(stack)
        try:
            idx = subs.rindex("0")
            subs = subs[:idx + 1] + "110" * remains + subs[idx + 1:]
        except:
            subs = "110" * remains + subs
        answer.append(subs)
    return answer
