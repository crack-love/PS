l,r,a=map(int,input().split())
d=min(abs(l-r),a)
print((min(l,r)+d+(a-d)//2)*2)