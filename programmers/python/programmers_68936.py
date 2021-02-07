import collections

def solution(arr):
    answer = []
    n = len(arr)

    temp = quad_encoding(arr, n, 0, 0, n, n, answer)
    if not answer:
        return [0, 1] if temp == 1 else [1, 0]
    answer = collections.Counter(answer)

    return answer[0], answer[1]

def quad_encoding(arr, n, x1, y1, x2, y2, answer):
    if n == 1:
        return arr[y1][x1]

    n //= 2

    encoded_lu = quad_encoding(arr, n, x1, y1, x2, y2, answer)
    encoded_ru = quad_encoding(arr, n, x1 + n, y1, x2 + n, y2, answer)
    encoded_lb = quad_encoding(arr, n, x1, y1 + n, x2, y2 + n, answer)
    encoded_rb = quad_encoding(arr, n, x1 + n, y1 + n, x2 + n, y2 + n, answer)

    if encoded_lu == encoded_ru == encoded_lb == encoded_rb:
        return encoded_lu

    answer.append(encoded_lu)
    answer.append(encoded_ru)
    answer.append(encoded_lb)
    answer.append(encoded_rb)
    return
