cl=0
ct = 0
for _ in range(9):
    s  = input()
    if s=="Lion":
        cl+=1
    else:
        ct+=1
print("Tiger" if ct > cl else "Lion")