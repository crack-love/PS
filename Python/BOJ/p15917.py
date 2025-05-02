ans = []
s = set()
v = 1
while v < 2**31:
    s.add(v)
    v = v*2
for _ in range(int(input())):
    q = int(input())
    ans.append(1 if q in s else 0)
print(*ans, sep='\n')