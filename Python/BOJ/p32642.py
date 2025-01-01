import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
ds = input().split()
ans = 0
st = 0
for x in ds:
    st += 1 if x == "1" else -1
    ans += st
print(ans)