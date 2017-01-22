terms = []
for a in range(2,101):
    for b in range(2,101):
        term = a ** b
        if term not in terms:
            terms.append(term)
print len(terms)
