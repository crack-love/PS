import sys
def input(): return sys.stdin.readline().strip()
ctp = {'.':0,'k':0,'p':1,'n':3,'b':3,'r':5,'q':9}
p0 = 0
p1 = 0
for _ in range(8):
    for c in input():
        if c.islower():
            p0 += ctp[c]
        elif c.isupper():
            p1 += ctp[c.lower()]
print(p1-p0)