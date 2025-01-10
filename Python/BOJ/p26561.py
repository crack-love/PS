import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
ans = []
for _ in range(n):
    p,t=map(int,input().split())
    p=p-int(t/7)+int(t/4)
    ans.append(p)
print(*ans,sep='\n')