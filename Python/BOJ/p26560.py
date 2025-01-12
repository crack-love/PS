import sys
def input(): return sys.stdin.readline().strip()
n  = int(input())
ans = []
for _ in range(n):
    s = input()
    ans.append(s if s.endswith(".") else s + ".")
print(*ans, sep='\n')