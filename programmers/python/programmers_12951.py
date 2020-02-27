def solution(s):
	answer = ""
	
	s_list = s.lower().split(" ")
	for i in range(len(s_list)):
		answer += s_list[i].capitalize() + " "
		
	return answer[:-1]
