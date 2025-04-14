n, m = map(int, (input(), input()))
ans = m
for _ in range(n):
    a,b=map(int,input().split())
    m += a- b
    if m < 0:
        ans = 0
        break
    ans = max(ans, m)
print(ans)