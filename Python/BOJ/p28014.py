n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(n):
    if i < n-1 and a[i] > a[i+1]:
        continue
    else:
        ans += 1
print(ans)