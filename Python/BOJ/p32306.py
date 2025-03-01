a = [*map(int,input().split())]
b = [*map(int,input().split())]
av = a[0]+a[1]*2+a[2]*3
bv = b[0]+b[1]*2+b[2]*3
print (1 if av > bv else 2 if av < bv else 0)
