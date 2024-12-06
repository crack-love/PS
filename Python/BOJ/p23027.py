import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
s = input_line()
s1 = ['A']*len(s)
if 'A' in s:
    for i in range(len(s)):
        if s[i]=='B' or s[i]=='C' or s[i] == 'D' or s[i] == 'F':
            s1[i]='A'
        else:
            s1[i]=s[i]
elif 'B' in s:
    for i in range(len(s)):
        if s[i]=='C' or s[i] == 'D' or s[i] == 'F':
            s1[i] = 'B'
        else:
            s1[i]=s[i]
elif 'C' in s:
    for i in range(len(s)):
        if s[i] == 'D' or s[i] == 'F':
            s1[i] = 'C'
        else:
            s1[i]=s[i]
print(''.join(s1))