import sys
def input(): return sys.stdin.readline().strip()
t={'a':'4','e':'3','i':'1','o':'0','s':'5'}
s = input()
s1 = (t[x] if x in t else x for x in s)
print(*s1, sep='')