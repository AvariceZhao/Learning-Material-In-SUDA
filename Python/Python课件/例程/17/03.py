#数字符（串）和数

def change(b, s):
    h = 0
    for c in s:
        h = h * b + ord(c) - 48
        #print("*", h)
    return h

#print("123"+1)
#print("123"+"1")
#print(change(10, "123") + 1)
#print(change(8, "123") + 1)