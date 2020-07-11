from collections import defaultdict
import re

def solution(word, pages):
    mScores = []
    webs = defaultdict(lambda: [0, 0])
    html = [[] for _ in range(len(pages))]
    check = []
    
    for i in range(len(pages)):
        html[i] = pages[i]
        
        urlmatch = re.compile('<meta(.+?)/>')
        mo = urlmatch.search(html[i]).group()
        url = mo.split(' ')[2].split('"')[1]
        check.append(url)
        
        wordmatch = re.sub('[^a-z]+', '.', html[i].lower()).split('.').count(word.lower())
        webs[url][0] += wordmatch
        
        linkmatch = re.compile('<a.href(.+?)>')
        mo = linkmatch.findall(html[i])
        for j in range(len(mo)):
            webs[mo[j][2:-1]][1] += (webs[url][0] / len(mo))
    
    for key, val in webs.items():
        if key in check:
            mScores.append([val[0] + val[1], check.index(key)])
    mScores = sorted(mScores, key=lambda x: (-x[0], x[1]))
    return mScores[0][1]
