a = [int(input()) for _ in range(10)]
s = sum(a)
ans = 0
for i in range(10):
    if s - a[i] == a[i]:
        ans = a[i]
print(ans)