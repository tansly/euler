def ispal(N):
    s = str(N)
    return s == s[::-1]

maximum = -1
x = 100
while x < 1000:
    y = x
    while y < 1000:
        p = x * y
        if p > maximum and ispal(p):
            maximum = p
        y += 1
    x += 1
print maximum
