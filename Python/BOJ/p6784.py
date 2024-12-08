import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
vs  = []
for _ in range(n):
    vs.append(input_line())
ans = 0
for i in range(n):
    v = input_line()
    ans += 1 if v == vs[i] else 0
print(ans)