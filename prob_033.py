def gcd(x, y):
    if x % y == 0:
        return y
    else:
        return gcd(y, x%y)

def ratSimp(rat):   # simplify rationals
    GCD = gcd(rat[0], rat[1])
    result = [rat[0]/GCD, rat[1]/GCD]
    return result[0] if result[1] == 1 else result

def ratMul(rat1, rat2):  # multiply rationals
    if type(rat1) != list:
        rat1 = [rat1, 1]
    if type(rat2) != list:
        rat2 = [rat2, 1]
    result = [(rat1[0] * rat2[0]), (rat1[1] * rat2[1])]
    return ratSimp(result)

def digit_cancel(rat):
    a = str(rat[0])
    b = str(rat[1])
    if a[0] in b:
        b = b[1 - b.index(a[0])]
        a = a[1]
    elif a[1] in b:
        b = b[1 - b.index(a[1])]
        a = a[0]
    return [int(a), int(b)]

fractions = []
a = 10
while a < 100:
    b = a + 1
    while b < 100:
        if a % 10 != 0 and b % 10 != 0 and ratSimp(digit_cancel([a, b])) == ratSimp([a, b]):
            if ratSimp([a, b]) != [a, b] and digit_cancel([a, b]) != [a, b]:
                fractions.append([a, b])
        b += 1
    a += 1
print fractions
print reduce(ratMul, fractions)
