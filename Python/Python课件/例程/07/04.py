#基本循环结构

lst = list(range(0, 20, 3))

#定次循环
for item in lst:
    print(item)
print("-" * 40, 1)

#定次循环
#i = 0
for i in range(len(lst)):
#while i < len(lst):
    print(lst[i])
    #i += 1
print("-" * 40, 2)

#不定次循环
i = 0
while lst[i] < 15:
    print(lst[i])
    i += 1
print("-" * 40, 3)

#不定次循环
for item in lst:
    if item < 5:
        continue
    if item < 15:
        print(item)
    else:
        break
print("-" * 40, 4)

#不定次循环
i = 0
while True:
    if lst[i] < 15:
        print(lst[i])
        i += 1
    else:
        break
