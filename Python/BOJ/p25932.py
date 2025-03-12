for _ in range(int(input())):
    a = input().split()
    print(*a)
    if a.count('18')>0 and a.count('17')>0:
        print('both')
    elif a.count('18')>0:
        print('mack')
    elif a.count('17')>0:
        print('zack')
    else:
        print('none')
    print()