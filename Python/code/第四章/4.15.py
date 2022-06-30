x1=float(input("输入圆心坐标x1.y1半径r和一个点x2.y2"))
y1=float(input(""))
r=float(input(""))
x2=float(input(""))
y2=float(input(""))

if((x2-x1)**2+(y2-y1)**2<=r**2):
    print("点在圆内")
else:
    print("点在圆外")


