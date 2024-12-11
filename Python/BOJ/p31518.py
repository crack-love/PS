import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
fail = False
for _ in range(3):
    a = input_map(int)
    if 7 not in a:
        fail = True
print(777 if not fail else 0)