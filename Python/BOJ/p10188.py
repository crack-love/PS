import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
ans = []
for _ in range(n):
    x,y=map(int,input().split())
    ans.append(('X'*x+'\n')*y)
print(*ans, sep='\n')