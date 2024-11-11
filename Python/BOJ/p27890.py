v, n = map(int, input().split())
for _ in range(n):
    v = int(v / 2) ^ 6 if v % 2 == 0 else (v * 2) ^ 6
print(v)