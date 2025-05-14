k = int(input())
d1,d2 = map(int,input().split())
#k**2 = (d1-d2)/2**2 + h**2
h2 = (k**2-((d1-d2)/2)**2)
print(h2)