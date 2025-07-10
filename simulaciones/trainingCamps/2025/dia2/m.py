import math

[n, r] = map(lambda x : int(x), input().split(' '))

half_theta = math.pi/n
sin = math.sin(half_theta)
R = (r*sin) / (1 - sin)
print(R)
