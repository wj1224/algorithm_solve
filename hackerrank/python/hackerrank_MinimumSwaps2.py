#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    def swap(a, b):
        temp = arr[a]
        arr[a] = arr[b]
        arr[b] = temp
    res = 0
    idx = 0
    while True:
        if idx >= len(arr):
            break
        if idx + 1 == arr[idx]:
            idx += 1
            continue
        swap(idx, arr[idx] - 1)
        res += 1
    return res
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
