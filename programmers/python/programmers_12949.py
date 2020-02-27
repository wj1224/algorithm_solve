import numpy as np

def solution(arr1, arr2):
	answer = np.matmul(np.asarray(arr1), np.asarray(arr2)).tolist()
	return answer
