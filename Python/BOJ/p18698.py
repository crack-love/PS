for _ in range(int(input())):
    v = 0
    for c in input():
        if c == 'D':
            break
        else:
            v+=1
    print(v)