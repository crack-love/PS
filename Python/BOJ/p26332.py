import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
ans = []
for _ in range(n):
    a,b = map(int,input().split())
    ans.append(f"{a} {b}")
    if a < 2:
        ans.append(a*b)
    else:
        ans.append((a-1)*(b-2)+b)
print(*ans, sep="\n")