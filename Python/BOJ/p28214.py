n,k,p=map(int,input().split())
ans = 0
a = input().split()
for i in range(n):
    b = a[i*k:(i+1)*k]
    ans += 1 if b.count('0') < p else 0
print(ans)