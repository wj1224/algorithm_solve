def solution(record):
    answer = []
    oper = []
    d = {}
    for r in record:
        oper.append(r.split())
    for i in oper:
        if i[0] != "Leave":
            d[i[1]] = i[2]
    for i in oper:
        if i[0] == "Enter":
            answer.append(d[i[1]] + "님이 들어왔습니다.")
        elif i[0] == "Leave":
            answer.append(d[i[1]] + "님이 나갔습니다.")
    return answer
