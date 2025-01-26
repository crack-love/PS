g,p,t=map(int,input().split())
a0 = g*p
a1 = g+t*p
print(0 if a0==a1 else 1 if a0<a1 else 2)