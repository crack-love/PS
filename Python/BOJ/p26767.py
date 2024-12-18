import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
for x in range(1,n+1):
    if x % 7 == 0 and x % 11 != 0:
        print("Hurra!")
    elif x % 7 != 0 and x % 11 == 0:
        print("Super!")
    elif x % 7 == 0 and x % 11 == 0:
        print("Wiwat!")
    else:
        print(x)