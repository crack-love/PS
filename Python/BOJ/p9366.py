for i in range(int(input())):
    a,b,c=map(int,input().split())
    print(f'Case #{i+1}: ', end='')
    if max(a,b,c) >= sum(sorted((a,b,c))[:2]): print('invalid!')
    elif a==b==c : print('equilateral')
    elif a==b or b==c : print('isosceles')
    else: print('scalene')