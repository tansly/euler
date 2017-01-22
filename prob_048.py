total = 0
n = 1
while n <= 1000:
    total += n**n
    n += 1
print str(total)[-10:]
