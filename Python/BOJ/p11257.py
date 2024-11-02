n = int(input())
ans = []
for _ in range(n):
    i, v0, v1, v2 = list(map(int, input().split()))
    total = v0 + v1 + v2
    ispass = v0 >= 35 * 0.3 and v1 >= 25 * 0.3 and v2 >= 40 * 0.3 and total >= 55
    passstr = "PASS" if ispass else "FAIL"
    ans.append(f"{i} {v0+v1+v2} {passstr}")
for x in ans:
    print(x)