def digit_count(n):
    count = 0
    while n > 0:
        n /= 10
        count += 1
    return count

fib1 = 1
fib2 = 1
index = 2
while digit_count(fib2) < 1000:
    fib1, fib2 = fib2, fib1 + fib2
    index += 1
print index
