a,b=map(int,input().split())
sm = sum(i for i in range(1, a)) % 14579
ans = 1
for i in range(a,b+1):
    sm = (sm + i) % 14579
    ans = (ans * sm) % 14579
print(ans)