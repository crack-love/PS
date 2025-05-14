for i in range(int(input())):
    n,d,a,b,f=map(float,input().split())
    print(f'{int(n)} {f*d/(a+b):.2f}')