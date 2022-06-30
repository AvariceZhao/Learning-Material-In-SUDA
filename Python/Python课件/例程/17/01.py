#字符和汉字的编码

s1 = "hello你好"
print("%d" % ord(s1[0]))
print("%d" % ord(s1[5]))
print("%d" % ord(s1[6]))
print("%c" % 20320)
print("%c" % 22909)
print("-"*40)

#可切片
print(s1[2:6])
print("-"*40)

#可迭代遍历
for c in s1:
    print(c)
print("-"*40)

lst = [c for c in s1]
print(lst)