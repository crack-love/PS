import random
import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
sets = []
for _ in range(n):
    _, *a = input().split()
    sets.append(a)
pi = random.randint(0,n-1)
ps = sets[pi]
print(len(ps))
while len(ps) > 0:
    pri = random.randint(0,len(ps)-1)
    print(ps[pri])
    ps.pop(pri)