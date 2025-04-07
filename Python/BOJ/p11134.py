for _ in range(int(input())):
    a,b=map(int,input().split())
    print(int(a/b if a%b==0 else a/b+1))
