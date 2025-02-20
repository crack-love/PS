s = int(input())
while s%10==0:
    s/=10
    if s==0:
        break
if (s==0):
    print(0)
else:
    print(str(int(s)).count('0'))