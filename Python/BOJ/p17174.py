n,m=map(int,input().split())
ans = 0
while n > 0:
    ans += n
    n //= m
print(ans)