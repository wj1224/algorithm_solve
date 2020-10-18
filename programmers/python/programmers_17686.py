import re

def solution(files):
    nums = re.compile('([0-9]+)')
    return sorted(files, key=lambda x: (re.split(nums, x)[0].lower(), int(re.split(nums, x)[1])))
