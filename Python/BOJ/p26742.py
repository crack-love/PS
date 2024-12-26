import sys
def input(): return sys.stdin.readline().strip()
s = input()
bc = sum(1 if x =='B' else 0 for x in s)
cc = sum(1 if x =='C' else 0 for x in s)
print(int(bc/2)+int(cc/2))