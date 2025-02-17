n,m=map(int,input().split())
ans = 0
for _ in range(n):
    s = input()
    ans += 1 if '+' in s else 0
print(ans)