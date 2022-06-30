import math
x1=float(input(""))
y1=float(input(""))
x2=float(input(""))
y2=float(input(""))
cosa=abs(x1*x2+y1*y2)/(math.sqrt(x1**2+y1**2)*math.sqrt(x2**2+y2**2))
print(cosa)
