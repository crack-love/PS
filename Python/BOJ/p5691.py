while True:
    a,b=map(int,input().split())
    if a == 0 and b == 0:
        break
    c = 2*min(a,b)-max(a, b)
    print(c)