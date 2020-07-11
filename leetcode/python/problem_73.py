class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row_flag, col_flag = False, False
        
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                row_flag = True
        for j in range(len(matrix[0])):
            if matrix[0][j] == 0:
                col_flag = True
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if row_flag:
            for i in range(len(matrix)):
                matrix[i][0] = 0
        if col_flag:
            for j in range(len(matrix[0])):
                matrix[0][j] = 0
