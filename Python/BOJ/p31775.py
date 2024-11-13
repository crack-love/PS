s0 = input()
s1 = input()
s2 = input()
c = ["l", "k", "p"]
ans = "PONIX"
if s0[0] in c:
    c.remove(s0[0])
    if s1[0] in c:
        c.remove(s1[0])
        if s2[0] in c:
            ans = "GLOBAL"
print(ans)