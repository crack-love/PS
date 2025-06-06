vowels = "aeiou"
for _ in range(int(input())):
    s = input().lower()
    vwc = sum(1 for c in s if c in vowels)
    notalph = sum(1 for c in s if not c.isalpha())
    print(len(s)-vwc-notalph, vwc)
