def solution(m, musicinfos):
    answer = '(None)'
    ltime = 0
    m = m.replace('C#', 'H').replace('D#', 'I').replace('F#', 'J').replace('G#', 'K').replace('A#', 'L')

    for info in musicinfos:
        stime, etime, title, score = info.split(',')
        stime = int(stime[:2]) * 60 + int(stime[3:])
        etime = int(etime[:2]) * 60 + int(etime[3:])
        ptime = etime - stime + 1
        score = score.replace('C#', 'H').replace('D#', 'I').replace('F#', 'J').replace('G#', 'K').replace('A#', 'L')
        
        num_iter, mod = ptime // len(score), ptime % len(score)
        musicscore = score * num_iter + score[:mod]
        
        if m in musicscore:
            if answer == '(None)' or (answer != '(None)' and ptime > ltime):
                answer = title
                ltime = ptime
            else:
                pass
        else:
            pass
    
    return answer
