n = int(input())
ans = 0
for i in range(1,n+1):
    s = str(i)
    ans += s.count('3')+s.count('6')+s.count('9')
print(ans)
