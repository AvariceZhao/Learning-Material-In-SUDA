import random,math
PI=3.1415926
a=random.uniform(10,50)
b=random.uniform(10,50)
x=complex(a,b)
norm=math.sqrt(a**2+b**2)
angle=math.atan(b/a)*(180/PI)
print(f'{a:>7.2f}+{b:>7.2f}j')
print("%7.2f"%norm)
print("%7.2f"%angle)