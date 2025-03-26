for _ in range(int(input())):
    n= int(input())
    print(f'Pairs for {n}: ',end='')
    print(*(f'{i} {n-i}' for i in range(1,n//2+1) if i != n-i), sep=', ')