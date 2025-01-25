s = input()
ans = []
i = 0
while i < len(s):
    ans.append(s[i])
    i = i + (ord(s[i])-ord('A')+1)
print(*ans, sep='')