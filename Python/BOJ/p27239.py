v = int(input())
a = (v-1)%8+ord('a')
b = int(((v-1)/8)+1)
print(f"{chr(a)}{b}")