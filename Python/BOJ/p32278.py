import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
if -2**15 <= n and n <= 2**15-1:
    print("short")
elif -2**31 <= n and n <= 2**31-1:
    print("int")
else:
    print("long long")