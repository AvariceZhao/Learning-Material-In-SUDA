#字符串的访问特性

s = "hello"
print("s = ", s)
print("1 -> id(s) = ", id(s))

s = "world"
print("s = ", s)
print("2 -> id(s) = ", id(s))

#s[0] = "x"
#print("3 -> id(s) = ", id(s))

s += " abc"
print("4 -> id(s) = ", id(s))
print(s)