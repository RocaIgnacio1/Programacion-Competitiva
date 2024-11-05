n = int(input())

number = input()
decimal = int(number.split('.')[1])
accum_decimal = decimal

ans = 0
for i in range(n):
    number = input()
    decimal = int(number.split('.')[1])
    accum_decimal += decimal
    if accum_decimal % 100 != 0:
        ans += 1
        
print(ans)