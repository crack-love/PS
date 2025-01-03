import sys
def input(): return sys.stdin.readline().strip()
t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = 1
    for i in range(1,n+1):
        v *= i
        v %= 10
    ans.append(v)
print(*ans, sep="\n")