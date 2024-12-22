import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
ans = []
for _ in range(n):
    a,b=input_map(float)
    ans.append(abs(a-b))
for x in ans:
    print(f"{x:.1f}")