n = int(input())
ss = map(int, input().split())
t, p = map(int, input().split())
tc = 0
for s in ss:
    if s >= 1:
        tc += int((s - 1) / t) + 1
pc = int(n / p)
ppc = n % p
print(tc)
print(f"{pc} {ppc}")