i=int(input(""))
if i<100000:
    print(i*1.015)
elif i>=100000 and i<500000:
    print(i*1.02)
elif i>=500000 and i<1000000:
    print(i*1.03)
else:
    print(i*1.035)