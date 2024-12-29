import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
ans = []
for _ in range(n):
    x,y,f=map(int,input().split())
    x1=x
    y1=y
    for _ in range(f):
        if x1>y1:
            x1=int(x1/2)
        else:
            y1=int(y1/2)
    ans.append(f"Data set: {x} {y} {f}")
    ans.append(f"{max(x1,y1)} {min(x1,y1)}")
    ans.append("")
for x in ans:
    print(x)
