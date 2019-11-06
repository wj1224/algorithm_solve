def solution(bridge_length, weight, truck_weights):
	answer = 0
	sum = 0
	i = 0
	bridge = []
	while True:
		if i < len(truck_weights):
			if (len(bridge) == 0 or sum + truck_weights[i] <= weight):
				bridge.append([truck_weights[i], answer])
				sum += truck_weights[i]
				i+= 1
		if len(bridge) != 0 and (bridge[0][1] + bridge_length) <= (answer + 1):
			sum -= bridge[0][0]
			bridge.pop(0)
		answer += 1
		if (i >= len(truck_weights) and len(bridge) == 0):
			break
	answer += 1
	return answer