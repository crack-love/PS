a = [1,0,0,2]
for c in input():
    if c == 'A':
        a[0],a[1] = a[1],a[0]
    elif c=='B':
        a[0],a[2] = a[2],a[0]
    elif c =='C':
        a[0], a[3] = a[3],a[0]
    elif c == 'D':
        a[1], a[2] = a[2], a[1]
    elif c == 'E':
        a[1], a[3] = a[3], a[1]
    elif c == 'F':
        a[2], a[3] = a[3], a[2]
print(a.index(1)+1)
print(a.index(2)+1)