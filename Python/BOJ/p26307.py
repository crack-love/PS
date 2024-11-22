import sys
def input_line(): return sys.stdin.readline().strip()
def input_one(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())
h,m = input_unpack(int)
bm = 21*60
em = (12+h)*60+m
print(em-bm)