import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
s = input_line()
n = int(input_line())
ans = 0
for _ in range(n):
    if s[:5] == input_line()[:5]:
        ans += 1
print(ans)