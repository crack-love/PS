n = int(input())
ans = 0
for i in range(n):
    s = sum(map(int,input().split()))
    ans += s
print(ans)