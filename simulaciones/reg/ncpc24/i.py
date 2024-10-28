s = int(input(), 2)
d = int(input(), 2)
m = int(input(), 2)

day: int = 0

# print(s, d, m)
    
days_until_0 = 0
mm = m
while (mm > 0):
    days_until_0 += 1
    mm = int(mm / 2)
    if mm <= 0: break
    
# print(days_until_0, d)
if (days_until_0 > d and s > m):
    print("Infinite money!")
    exit(0)

while (m > 0):
    day += 1
    m = int(m / 2)
    if m <= 0: break
    if (day%d == 0):
        m += s
    
    #if (day >= 1e6):
    #    break
    # print(m)

print("{0:b}".format(day))