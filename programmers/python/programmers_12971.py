def solution(sticker):
    if len(sticker) == 1:
        return sticker[0]
    mem = [[0 for _ in range(len(sticker))] for _ in range(2)]
    mem[0][0] = mem[0][1] = sticker[0]
    mem[1][1] = sticker[1]

    for i in range(2, len(sticker)):
        if i != len(sticker) - 1:
            mem[0][i] = max(mem[0][i - 2] + sticker[i], mem[0][i - 1])
        else:
            mem[0][i] = max(mem[0][i - 2], mem[0][i - 1])
        mem[1][i] = max(mem[1][i - 2] + sticker[i], mem[1][i - 1])

    return max(mem[0][-1], mem[1][-1])
