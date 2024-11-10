t = ["a", "i", "u", "e", "o"]
n = input()
s = input()
ans = 0
for c in s:
    if c in t:
        ans += 1
print(ans)