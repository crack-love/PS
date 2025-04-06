for i in range(int(input())):
    print(f'String #{i+1}')
    s = ''
    for c in input():
        c = ord(c)+1
        if c == ord('Z')+1:
            c = ord('A')
        s += chr(c)
    print(s)
    print()