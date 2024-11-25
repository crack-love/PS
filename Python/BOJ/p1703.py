import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())
ans = []
while True:
    a = list(input_map(int))
    if a[0] == 0:
        break
    v = 1
    for i in range(1, len(a), 2):
        v *= a[i]
        v -= a[i+1]
    ans.append(v)
for x in ans:
    print(x)