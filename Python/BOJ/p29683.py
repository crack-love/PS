n,d=map(int,input().split())
a =map(int,input().split())
s = sum(int(x/d) for x in a)
print(s)