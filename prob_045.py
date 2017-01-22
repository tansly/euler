a = 1
b = 1
c = 1
found = False

def t(n):
    return n * (n + 1) / 2

def p(n):
    return n * (3 * n - 1) / 2

def h(n):
    return n * (2 * n - 1)

while True:
    if t(a) > p(b):
        b += 1
    if t(a) < p(b):
        a += 1
    if t(a) == p(b):
        test = t(a)
        while h(c) < test:
            c += 1
        if h(c) == test:
            print test
            found = True
            a += 1
        else:
            a += 1
