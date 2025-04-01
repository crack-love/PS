n,t=map(int,input().split())
a = list(map(int,input().split()))
ans = 0
s = 0
for v in a:
    if s + v > t:
        break
    s += v
    ans += 1
print(ans)