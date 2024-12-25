import sys
def input(): return sys.stdin.readline().strip()
n,_=map(int,input().split())
gs = map(int,input().split())
caps= [4,11,23,40,60,77,89,96, 100]
ans = []
for x in gs:
    v = int(x * 100 / n)
    for i in range(len(caps)):
        if v <= caps[i]:
            ans.append(str(i+1))
            break
print(' '.join(ans))