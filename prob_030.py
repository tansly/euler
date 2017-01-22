def sum_(n):
    if n / 10 == 0:
        return n ** 5
    else:
        return (n % 10) ** 5 + sum_(n / 10)

n = 10
total = 0
while n < 1000000:
    if n == sum_(n):
        total += n
    n += 1
print total
