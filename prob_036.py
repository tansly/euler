def palindromes(n):
    result = []
    x = 0
    while x < n:
        if str(x) == str(x)[::-1] and bin(x)[2:] == bin(x)[2:][::-1]:
            result.append(x)
        x += 1
    return result

print sum(palindromes(1000000))
