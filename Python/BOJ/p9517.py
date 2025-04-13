k = int(input())-1
ts = 0
for _ in range(int(input())):
    t,z = (lambda a,b: (int(a), b))(*input().split())
    ts += t
    if ts >= 210:
        break
    if z=='T':
        k = (k+1)%8
    elif z =='P' or z=='N':
        continue
print(k+1)