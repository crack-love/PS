while True:
    b,n = map(int,input().split())
    if b==0 and n==0 :
        break
    x = int(b**(1/n))
    y = int(b**(1/n)+1)
    if abs(b-x**n) > (abs(b-y**n)):
        print(y)
    else:
        print(x)

    # ans = 0
    # ansv = b
    # for i in range(1,b+1):
    #     df = abs(i**n - b )
    #     if df < ansv:
    #         ans = i
    #         ansv = df
    # print(ans)