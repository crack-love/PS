u,v=map(int,input().split())
a=1
b=u*2
c=v
if b**2-4*a*c==0:
    x = (-b)/(2*a)
    print(int(x))
else:
    x = (-b-((b**2-4*a*c)**0.5))/(2*a)
    y = (-b+((b**2-4*a*c)**0.5))/(2*a)
    print(int(x),int(y))