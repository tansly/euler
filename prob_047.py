def factorize(number):
    power = 0
    factors = []
    while number % 2 == 0:
        number/= 2
        power += 1
    if power != 0:
        factors.append((2, power))
    x = 3
    while number > 1:
        power = 0
        while number % x == 0:
            number /= x
            power += 1
        if power != 0:
            factors.append((x, power))
        x += 2
    return factors

def intersects(l1, l2):
    for i in l1:
        if i in l2:
            return True
    return False

x = 7
fac0 = factorize(3)
fac1 = factorize(4)
fac2 = factorize(5)
fac3 = factorize(6)
found = False
while not found:
    fac0, fac1, fac2 = fac1, fac2, fac3
    fac3 = factorize(x)
    if len(fac0) == len(fac1) == len(fac2) == len(fac3) == 4:
        if (not intersects(fac0, fac1)) and (not intersects(fac0, fac2)) and (not intersects(fac0, fac3)) and (not intersects(fac1, fac2)) \
                and (not intersects(fac1, fac3)) and (not intersects(fac2, fac3)):
            break
    x += 1
print x - 3
