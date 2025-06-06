n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(n-1,-1,-1):
    if i == 0:
        ans += a[0]
    elif a[i]-a[i-1] > 1:
        ans += a[i]
print(ans)