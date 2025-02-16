n = int(input())
for _ in range(n):
    s,a,b=input().split()
    print(s[0:int(a)]+s[int(b):])