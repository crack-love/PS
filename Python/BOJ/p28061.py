n = int(input())
a = list(map(int,input().split()))
mx = 0
for i in range(n):
    mx = max(a[i]-(n-i), mx)
print(mx)