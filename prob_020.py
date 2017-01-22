def sum_digit(n):
    total = 0
    while n != 0:
        total += n % 10
        n /= 10
    return total

def factorial(n):
    if n <= 0:
        return 1
    return n * factorial(n - 1)
