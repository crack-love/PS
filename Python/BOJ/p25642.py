import sys
def input_line(): return sys.stdin.readline().strip()
def map_line(f): return map(f, input_line().split())

a,b= map_line(int)
atrun = True
while True:
    if atrun:
        b += a
        atrun = False
        if b >= 5:
            print("yt")
            break
    else:
        a += b
        atrun = True
        if a>=5:
            print("yj")
            break 