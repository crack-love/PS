import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
t = 1
ans = []
while True:
    a = list(input_map(int))
    n = a[0]
    a.pop(0)
    m = 0.0
    if n == 0:
        break
    if n % 2 == 1:
        m = a[int(n / 2)]
    if n % 2 == 0:
        m = (a[int(n / 2) - 1] + a[int(n / 2)]) / 2
    ans.append(f"Case {t}: {m:.1f}")
    t += 1
for x in ans:
    print(x)