#演示表达式值的多样性和部分等价性

a = 0
b = 1
if a < b:
    print("OK1.")

if a + b:
    print("OK2.")

if a * b:
    print("OK3.")

print("Finish.")
