while True:
    x,y=map(int,input().split())
    if x==0 and y==0:
        break
    v=int(x/y)
    print(f"{v} {x-v*y} / {y}")