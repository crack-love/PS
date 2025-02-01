n = int(input())
ans = []
for _ in range(n):
    d,f,p = map(float,input().split())
    ans.append(d*f*p)
for x in ans:
   print(f"${x:.2f}")