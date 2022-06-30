#生成器

def g_Fibonacci():
    a, b = 1, 1
    while True:
        yield a
        a, b = b, a + b
    return

x = g_Fibonacci()

for i in x:
    print(i)
    if i > 25:
        break

print("-"*40)

for i in x:
    print(i)
    if i > 100:
        break
