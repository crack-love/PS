ans = 0
for _ in range(int(input())):
    s = input()
    ans += 1 if "01" in s or "OI" in s else 0
print(ans)