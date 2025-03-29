for _ in range(int(input())):
    a,b=0,0
    for _ in range(int(input())):
        x,y = input().split()
        if x==y:
            continue
        elif x=='R' and y=='S' or x=='S' and y=='P' or x=='P' and y=='R':
            a+=1
        else:
            b+=1
    if a==b:
        print('TIE')
    else:
        print(f'Player {1 if a>b else 2}')