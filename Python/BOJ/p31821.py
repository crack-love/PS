n = int(input())
p = []
for _ in range(n):
    p.append(int(input()))
m = int(input())
ans = 0
for _ in range(m):
    ans += p[int(input())-1]
print(ans)