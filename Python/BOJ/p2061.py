k,l=map(int,input().split())
bd = False
for i in range(2,l):
    if k%i==0:
        print(f"BAD {i}")
        bd = True
        break
if bd == False:
    print("GOOD")