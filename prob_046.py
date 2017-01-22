def checkPrime(x):
    if x==1:
        return False
    elif x==2:
        return True
    elif x%2==0:
        return False
    else:
        n=3
        while n<x:
            if x%n==0:
                return False
            else:
                n+=2
    return True

def checksq(n, i):
    return (int(((n - i) / 2.0)**0.5))**2 == (n - i) / 2.0

n = 9
found = False
while not found:
    if not checkPrime(n):
        i = 2
        while i <= n - 2:
            if checkPrime(i) and checksq(n, i):
                break
            else:
                i += 1
            if i == n - 1:
                found = True
    if not found:
        n += 2
print n
