def jiecheng(a):
    if a==1:
        return 1
    else:
        return a*jiecheng(a-1)
print(4*6*jiecheng(6))#末尾4种选择，开头6种选择，中间剩余数字全排列