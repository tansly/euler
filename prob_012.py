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

def div_count(number):
    factors = factorize(number)
    result = 1
    for factor in factors:
        result *= factor[1] + 1
    return result

n = 1
found = False
while not found:
    tri = n * (n + 1) / 2
    if div_count(tri) < 500:
        n += 1
    else:
        found = True
print tri
