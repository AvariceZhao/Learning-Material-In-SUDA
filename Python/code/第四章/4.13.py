import math
flag=False
x1=float(input("please input x1 y1 x2 y2 x3 y3"))
y1=float(input(""))
x2=float(input(""))
y2=float(input(""))
x3=float(input(""))
y3=float(input(""))
side1=math.sqrt((x1-x2)**2+(y1-y2)**2)
side2=math.sqrt((x1-x3)**2+(y1-y3)**2)
side3=math.sqrt((x3-x2)**2+(y3-y2)**2)
if side1+side2>side3 or side1+side3>side2 or side2+side3>side1:
    flag=True
if  flag:
    s=(side1+side2+side3)/2
    area=math.sqrt(s*(s-side1)*(s-side2)*(s-side3))
    print("面积=%-7.2f"%area)
    print("周长=%.2f"%(side1+side2+side3))
else:
    print("无法构成三角形")
