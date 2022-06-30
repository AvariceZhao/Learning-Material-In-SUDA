#演示浮点数值存储的误区

a = 1 / 3
b = 1 / 6
b *= 2
print(a==b)
print(id(a))
print(id(b))

print(id(1 / 3))
print(id(2 / 6))
print(id(1.5 / 4.5))
print(id(1 / 6 * 2))