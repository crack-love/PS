import sys
def input(): return sys.stdin.readline().strip()
a,b = map(int,input().split())
a1,b1 = map(int,input().split())
for i in range(1,5001):
    if (a+i)%b==0 and (a1+i)%b1==0:
        print(i)
        break