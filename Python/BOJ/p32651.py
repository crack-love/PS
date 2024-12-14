import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
print ("Yes" if n <= 100000 and n % 2024 == 0 else "No")