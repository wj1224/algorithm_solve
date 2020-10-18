def solution(msg):
    answer = []
    vocab = dict()
    
    for idx in range(1, 27):
        vocab[chr(idx + 64)] = idx
    idx += 1
    
    i = 0
    while i < len(msg):
        m = msg[i]
        j = i + 1
        while j < len(msg):
            if m + msg[j] not in vocab:
                break
            m += msg[j]
            j += 1
        else:
            j -= 1
        answer.append(vocab[m])
        vocab[m + msg[j]] = idx
        idx += 1
        i += len(m)
    
    return answer
