import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())

n = input_cast(int)
a = [False]*n
for x in input_map(int):
    a[x-1] = True
for i in range(n):
    if a[i] == False:
        print(i+1)
        break