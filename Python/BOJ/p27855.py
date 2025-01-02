import sys
def input(): return sys.stdin.readline().strip()
h,b=map(int,input().split())
v1 = h*3+b
h,b=map(int,input().split())
v2 = h*3+b
if v1>v2:
    print(*(1, v1-v2))
elif v2>v1:
    print(*(2, v2-v1))
else:
    print("NO SCORE")