def sum_divisors(number):
    total = 0
    for i in range(1, number):
        total += i if number % i == 0 else 0
    return total

def is_amicable(n1, n2):
    return sum_divisors(n1) == n2 and sum_divisors(n2) == n1

numbers = []
for a in range(1, 10000):
    numbers.append((a, sum_divisors(a)))

total = 0
for i in range(len(numbers)):
    for j in range(i + 1, len(numbers)):
        if numbers[i][0] == numbers[j][1] and numbers[i][1] == numbers[j][0]:
            total += numbers[i][0] + numbers[j][0]
print total
