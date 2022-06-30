#字符串作为函数参数

def demo(s):
	print("    id(s) = ", id(s))
	s = "abc"
	print("    id(s) = ", id(s))
	return s

a = "hello"

print("a = ", a)
print("id(a) = ", id(a))
a = demo(a)
print("a = ", a)
print("id(a) = ", id(a))
