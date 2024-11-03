# 4,2,3,5
a = int(input())
b = int(input())
ans = []
for i in range(b - a + 1):
    if i % 4 == 0 and i % 2 == 0 and i % 3 == 0 and i % 5 == 0:
        ans.append(f"All positions change in year {a+i}")
for a in ans:
    print(a)