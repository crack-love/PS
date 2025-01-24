n,x=map(int,input().split())
ans = -1
for _ in range(n):
    s,t=map(int,input().split())
    if s+t <= x:
        ans = max(ans,s)
print(ans)