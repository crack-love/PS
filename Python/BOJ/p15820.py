s1,s2 = map(int,input().split())
end = False
for i in range(s1):
    a,b = map(int,input().split())
    if a!=b:
        print("Wrong Answer")
        end = True
        break
if end == False:
    for i in range(s2):
        a,b = map(int,input().split())
        if a!=b:
            print("Why Wrong!!!")
            end = True
            break
if end == False:
    print("Accepted")