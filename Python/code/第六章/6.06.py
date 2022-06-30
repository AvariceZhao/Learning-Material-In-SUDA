d1={"a":5,"b":6,"c":7}
d2={"b":7,"c":8,"d":9}
s1=set()
s2=set()
for i in d1:
    s1.add(i)
for i in d2:
    s2.add(i)
print(s1&s2)