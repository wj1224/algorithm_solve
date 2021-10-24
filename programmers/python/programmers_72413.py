
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
import heapq

def create_costs_list(n, fares):
    costs = [[] for _ in range(n + 1)]

    for fare in fares:
        costs[fare[0]].append([fare[1], fare[2]])
        costs[fare[1]].append([fare[0], fare[2]])

    return costs

def dijkstra(n, s, costs, dst):
    if s == dst:
        return 0
    dist = [float('inf') for _ in range(n + 1)]
    dist[s] = 0
    pq = []
    heapq.heappush(pq, [0, s])    

    while pq:
        cur, start = heapq.heappop(pq)
        if dist[start] < cur:
            continue
        for end, cost in costs[start]:
            if cur + cost < dist[end]:
                dist[end] = cur + cost
                heapq.heappush(pq, [dist[end], end])

    return dist[dst]

def solution(n, s, a, b, fares):
    answer = float('inf')

    costs = create_costs_list(n ,fares)
    for i in range(1, n + 1):
        answer = min(answer, dijkstra(n, s, costs, i) + dijkstra(n, i, costs, a) + dijkstra(n, i, costs, b))

    return answer
