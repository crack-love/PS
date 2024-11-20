import sys
def input_line(): return sys.stdin.readline().strip()
def input_one(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())

t = input_one(int)
s = list(input_unpack(int))
while len(s) < 5:
    s.append(0)
v = 0
if s[0] > s[2]:
    v += (s[0]-s[2])*508
else:
    v += (s[2] - s[0])*108
if s[1] > s[3]:
    v += (s[1]-s[3])*212
else:
    v += (s[3]-s[1])*305
v += s[4]*707
v *= 4763
print(v)