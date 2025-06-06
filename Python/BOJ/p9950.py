while True:
    a,b,c = map(int, input().split())
    if a==0==b==c:
        break
    if a==0:
        a = c/b
    elif b ==0:
        b = c/a
    else:
        c = a*b
    print(int(a),int(b),int(c))