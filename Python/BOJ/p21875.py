s = input()
e = input()
a,b = abs(ord(s[0])-ord(e[0])), abs(int(s[1])-int(e[1]))
print(min(a,b), max(a,b))