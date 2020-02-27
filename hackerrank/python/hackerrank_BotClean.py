#!/usr/bin/python

# Head ends here
import math

def next_move(posr, posc, board):
	dirty_pos = []
	for i in range(len(board)):
		for j in range(len(board[i])):
			if board[i][j] == "d":
				dist = math.sqrt(((posr - i) ** 2) + ((posc - j) ** 2)) 
				dirty_pos.append([dist, i, j])
	dirty_pos.sort()
	if posr - dirty_pos[0][1] > 0:
		print("UP")
	elif posr - dirty_pos[0][1] < 0:
		print("DOWN")
	elif posc - dirty_pos[0][2] > 0:
		print("LEFT")
	elif posc - dirty_pos[0][2] < 0:
		print("RIGHT")
	else:
		print("CLEAN")

# Tail starts here

if __name__ == "__main__":
	pos = [int(i) for i in input().strip().split()]
	board = [[j for j in input().strip()] for i in range(5)]
	next_move(pos[0], pos[1], board)
