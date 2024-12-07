import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
t = int(input_line())
ans = []
for _ in range(t):
    h, m, a, d, ha, ma, aa, da = input_map(int)
    h += ha
    m += ma
    a += aa
    d += da
    h = max(h,1)
    m =max(m,1)
    a = max(a, 0)
    p = h + 5*m + 2*a + 2*d
    ans.append(p)
for x in ans:
    print(x)