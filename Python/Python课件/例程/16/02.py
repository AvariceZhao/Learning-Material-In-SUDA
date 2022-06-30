#字典 - 字母频度统计

data = "ACM brings together computing educators, researchers, \
and professionals to inspire dialogue, share resources, and \
address the field's challenges. As the world’s largest computing society, \
ACM strengthens the profession's collective voice through strong leadership, \
promotion of the highest standards, and recognition of technical excellence."

dic = dict()
data = data.upper()
for c in data:
    if "A" <= c <= "Z":
        dic[c] = dic.get(c, 0) + 1

i = 0
for k in sorted(dic):
    print("%s:%2d    " % (k, dic[k]), end="")
    i += 1
    print() if i % 4 == 0 else None
print()
