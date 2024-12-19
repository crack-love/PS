import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
s = [13,7,5,3,3,2]
v0 = 0
v1 = 1.5
a0 = list(input_map(int))
a1 = list(input_map(int))
for i in range(len(a0)):
    v0 += s[i]*a0[i]
    v1 += s[i]*a1[i]
print("cocjr0208" if v0 > v1 else "ekwoo")
