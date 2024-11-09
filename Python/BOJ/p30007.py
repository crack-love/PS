# w=a(x-1)+b
n = int(input())
ans = []
for _ in range(n):
    a, b, x = map(int, input().split())
    w = a * (x - 1) + b
    ans.append(w)
for x in ans:
    print(x)