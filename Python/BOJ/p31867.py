import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
k = input_line()
ec = 0
oc = 0
for c in k:
    if int(c)%2==0: 
        ec+=1
    else:
        oc+=1
print(0 if ec > oc else 1 if oc > ec else -1)