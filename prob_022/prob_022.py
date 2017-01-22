def sort_names(names):
    flag = True
    while flag:
        flag = False
        i = 0
        while i < len(names) - 1:
            if names[i] > names[i + 1]:
                names[i], names[i + 1] = names[i + 1], names[i]
                flag = True
            i += 1

def name_score(name, pos):
    score = 0
    for i in name:
        score += ord(i) - 64
    score *= pos
    return score

names = input()
sort_names(names)
total = 0
pos = 1
for name in names:
    total += name_score(name, pos)
    pos += 1
print total
