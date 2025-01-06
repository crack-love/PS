import sys
def input(): return sys.stdin.readline().strip()
n = input()
s = input()
print("Yes" if s.count(s[0]) == len(s) else "No")