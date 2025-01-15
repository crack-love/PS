import sys
def input(): return sys.stdin.readline().strip()
a,b=map(int,input().split())
n =int(input())
ans = []
for _ in range(n):
    v = int(input())
    ans.append((v,min(1000,v)*a + max(v-1000,0)*b))
for x in ans:
    print(*x)