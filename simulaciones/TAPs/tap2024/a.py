def calc(a, b, c):
    return a**2 + b**2 + c**2 - (a*b+b*c+c*a)

res = calc(69384, 16, 16)
print(res)