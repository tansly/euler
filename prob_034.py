def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def fac_digit_sum(n):
    if n / 10 == 0:
        return factorial(n)
    else:
        return factorial(n % 10) + fac_digit_sum(n / 10)

total = 0
n = 3
while n < 9999999:
    if n == fac_digit_sum(n):
        total += n
    n += 1
print total
