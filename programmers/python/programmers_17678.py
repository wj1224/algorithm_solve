import heapq
def solution(n, t, m, timetable):
    crew = []
    
    for tt in timetable:
        heapq.heappush(crew, int(tt[:2]) * 60 + int(tt[3:]))
    bus = [540]
    for i in range(n - 1):
        bus.append(bus[-1] + t)
    
    for i in range(len(bus)):
        for j in range(m):
            if len(crew) == 0:
                answer = bus[-1]
                break
            if i == len(bus) - 1 and j == m - 1 and bus[i] >= crew[0]:
                answer = heapq.heappop(crew) - 1
                break
            elif i == len(bus) - 1 and j == m - 1 and bus[i] < crew[0]:
                answer = bus[-1]
                break
            if bus[i] >= crew[0]:
                heapq.heappop(crew)
    
    div, mod = answer // 60, answer % 60
    if div < 10:
        h = '0' + str(div) + ':'
    else:
        h = str(div) +':'
    if mod < 10:
        m = '0' + str(mod)
    else:
        m = str(mod)
    
    return h + m
